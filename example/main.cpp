#include <csignal>
#include <pqrs/osx/iokit_hid_event_system_client.hpp>
#include <pqrs/osx/iokit_service_monitor.hpp>

namespace {
auto global_wait = pqrs::make_thread_wait();
}

int main(void) {
  std::signal(SIGINT, [](int) {
    global_wait->notify();
  });

  std::cout << "Type control-c to quit." << std::endl;

  auto time_source = std::make_shared<pqrs::dispatcher::hardware_time_source>();
  auto dispatcher = std::make_shared<pqrs::dispatcher::dispatcher>(time_source);

  pqrs::osx::iokit_hid_event_system_client client;

  if (auto matching_dictionary = IOServiceNameMatching("AppleUserHIDEventDriver")) {
    auto service_monitor = std::make_unique<pqrs::osx::iokit_service_monitor>(dispatcher,
                                                                              matching_dictionary);

    service_monitor->service_matched.connect([&](auto&& registry_entry_id, auto&& service_ptr) {
      std::cout << "service_matched registry_entry_id: 0x" << std::hex << registry_entry_id << std::dec << std::endl;

      client.reload_service_clients();

      pqrs::osx::iokit_registry_entry entry(service_ptr);

      if (auto vendor_id = entry.find_int64_property(CFSTR("VendorID"))) {
        std::cout << "    vendor_id " << *vendor_id << std::endl;
      }

      if (auto product_id = entry.find_int64_property(CFSTR("ProductID"))) {
        std::cout << "    product_id " << *product_id << std::endl;
      }

      if (auto manufacturer = entry.find_string_property(CFSTR("Manufacturer"))) {
        std::cout << "    manufacturer " << *manufacturer << std::endl;
      }

      if (auto product = entry.find_string_property(CFSTR("Product"))) {
        std::cout << "    product " << *product << std::endl;
      }

      if (auto serial_number = entry.find_string_property(CFSTR("SerialNumber"))) {
        std::cout << "    serial_number " << *serial_number << std::endl;
      }

      if (auto value = client.get_initial_key_repeat(registry_entry_id)) {
        std::cout << "    initial_key_repeat " << *value << std::endl;
      }

      if (auto value = client.get_key_repeat(registry_entry_id)) {
        std::cout << "    key_repeat " << *value << std::endl;
      }

      if (auto value = client.get_caps_lock_delay_override(registry_entry_id)) {
        std::cout << "    caps_lock_delay_override " << *value << std::endl;
      }

      client.set_caps_lock_delay_override(registry_entry_id, 0);
    });

    service_monitor->error_occurred.connect([](auto&& message, auto&& kern_return) {
      std::cerr << "error_occurred " << message << " " << kern_return << std::endl;
    });

    service_monitor->async_start();

    global_wait->wait_notice();

    CFRelease(matching_dictionary);
  }

  dispatcher->terminate();
  dispatcher = nullptr;

  std::cout << "finished" << std::endl;

  return 0;
}

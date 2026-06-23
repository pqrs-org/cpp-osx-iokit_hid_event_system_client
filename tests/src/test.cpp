#include <boost/ut.hpp>
#include <pqrs/osx/iokit_hid_event_system_client.hpp>

int main() {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "iokit_hid_event_system_client"_test = [] {
    pqrs::osx::iokit_hid_event_system_client client;

    expect(client.make_registry_entry_ids().size() > 0);
  };

  "invalid_registry_entry_id"_test = [] {
    pqrs::osx::iokit_hid_event_system_client client;

    constexpr pqrs::osx::iokit_registry_entry_id::value_t registry_entry_id(0);

    expect(client.get_initial_key_repeat(registry_entry_id) == std::nullopt);
    expect(client.get_key_repeat(registry_entry_id) == std::nullopt);
    expect(client.get_caps_lock_delay_override(registry_entry_id) == std::nullopt);

    client.set_initial_key_repeat(registry_entry_id, 0);
    client.set_key_repeat(registry_entry_id, 0);
    client.set_caps_lock_delay_override(registry_entry_id, 0);
  };

  return 0;
}

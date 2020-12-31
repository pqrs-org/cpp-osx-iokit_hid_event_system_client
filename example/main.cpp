#include <pqrs/osx/iokit_hid_event_system_client.hpp>

int main(void) {
  pqrs::osx::iokit_hid_event_system_client client;

  for (const auto& registry_entry_id : client.make_registry_entry_ids()) {
    std::cout << "registry_entry_id " << std::hex << registry_entry_id << std::dec << std::endl;

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
  }

  return 0;
}

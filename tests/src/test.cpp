#include <boost/ut.hpp>
#include <pqrs/osx/iokit_hid_event_system_client.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "iokit_hid_event_system_client"_test = [] {
    pqrs::osx::iokit_hid_event_system_client client;

    expect(client.make_registry_entry_ids().size() > 0);
  };

  return 0;
}

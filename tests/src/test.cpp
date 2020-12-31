#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit_hid_event_system_client.hpp>

TEST_CASE("iokit_hid_event_system_client") {
  pqrs::osx::iokit_hid_event_system_client client;

  REQUIRE(client.make_registry_entry_ids().size() > 0);
}

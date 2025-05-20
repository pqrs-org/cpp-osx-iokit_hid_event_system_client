[![Build Status](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/workflows/CI/badge.svg)](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/actions)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/blob/main/LICENSE.md)

# cpp-osx-iokit_hid_event_system_client

A wrapper class of IOHIDEventSystemClient and IOHIDServiceClient.

- Getting and setting properties:
  - kIOHIDServiceInitialKeyRepeatDelayKey
  - kIOHIDServiceKeyRepeatDelayKey
  - kIOHIDKeyboardCapsLockDelayOverrideKey

## Requirements

cpp-osx-iokit_hid_event_system_client depends the following classes.

- [pqrs::cf::array](https://github.com/pqrs-org/cpp-cf-array)
- [pqrs::cf::number](https://github.com/pqrs-org/cpp-cf-number)
- [pqrs::osx::iokit_types](https://github.com/pqrs-org/cpp-osx-iokit_types)

## Install

Copy `include/pqrs` and `vendor/vendor/include` directories into your include directory.

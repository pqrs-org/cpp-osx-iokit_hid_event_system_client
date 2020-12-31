[![Build Status](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/workflows/CI/badge.svg)](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/actions)
[![License](https://img.shields.io/badge/license-Boost%20Software%20License-blue.svg)](https://github.com/pqrs-org/cpp-osx-iokit_hid_event_system_client/blob/master/LICENSE.md)

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

### Using package manager

You can install `include/pqrs` by using [cget](https://github.com/pfultz2/cget).

```shell
cget install pqrs-org/cget-recipes
cget install pqrs-org/cpp-osx-iokit_hid_event_system_client
```

### Manual install

Copy `include/pqrs` directory into your include directory.

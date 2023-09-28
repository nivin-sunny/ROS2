// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:srv/Empty.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__EMPTY__STRUCT_H_
#define TUTORIAL_INTERFACES__SRV__DETAIL__EMPTY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Empty in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Empty_Request
{
  uint8_t structure_needs_at_least_one_member;
} tutorial_interfaces__srv__Empty_Request;

// Struct for a sequence of tutorial_interfaces__srv__Empty_Request.
typedef struct tutorial_interfaces__srv__Empty_Request__Sequence
{
  tutorial_interfaces__srv__Empty_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Empty_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Empty in the package tutorial_interfaces.
typedef struct tutorial_interfaces__srv__Empty_Response
{
  bool success;
} tutorial_interfaces__srv__Empty_Response;

// Struct for a sequence of tutorial_interfaces__srv__Empty_Response.
typedef struct tutorial_interfaces__srv__Empty_Response__Sequence
{
  tutorial_interfaces__srv__Empty_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__srv__Empty_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__EMPTY__STRUCT_H_

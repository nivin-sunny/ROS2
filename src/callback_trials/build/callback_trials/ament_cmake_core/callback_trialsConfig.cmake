# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_callback_trials_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED callback_trials_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(callback_trials_FOUND FALSE)
  elseif(NOT callback_trials_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(callback_trials_FOUND FALSE)
  endif()
  return()
endif()
set(_callback_trials_CONFIG_INCLUDED TRUE)

# output package information
if(NOT callback_trials_FIND_QUIETLY)
  message(STATUS "Found callback_trials: 0.0.0 (${callback_trials_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'callback_trials' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${callback_trials_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(callback_trials_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${callback_trials_DIR}/${_extra}")
endforeach()

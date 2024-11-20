cmake_minimum_required (VERSION 2.6...3.10.2)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    message (STATUS "OPENSSL found")

    set(CMAKE_C_FLAGS "-DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()

    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    message (STATUS "OpenSSL Not found.")
endif()

set(pkgName "qan_autoapi")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    else(CURL_FOUND)
        message(FATAL_ERROR "Could not find the CURL library and development files.")
    endif()
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/error_detail.c
    model/error_model.c
    model/estimate_gas_object.c
    model/filter_object.c
    model/input_call.c
    model/input_estimate_gas.c
    model/input_fee_history.c
    model/input_get_logs.c
    model/input_get_proof.c
    model/input_get_storage_at.c
    model/input_new_filter.c
    model/input_send_raw_transaction.c
    model/output_block_number.c
    model/output_call.c
    model/output_chain_id.c
    model/output_estimate_gas.c
    model/output_fee_history.c
    model/output_gas_price.c
    model/output_get_balance.c
    model/output_get_block_by_hash.c
    model/output_get_block_by_number.c
    model/output_get_block_receipts.c
    model/output_get_block_transaction_count_by_hash.c
    model/output_get_block_transaction_count_by_number.c
    model/output_get_code.c
    model/output_get_filter_changes.c
    model/output_get_filter_logs.c
    model/output_get_logs.c
    model/output_get_proof.c
    model/output_get_storage_at.c
    model/output_get_transaction_by_block_hash_and_index.c
    model/output_get_transaction_by_block_number_and_index.c
    model/output_get_transaction_by_hash.c
    model/output_get_transaction_count.c
    model/output_get_transaction_receipt.c
    model/output_max_priority_fee_per_gas.c
    model/output_new_block_filter.c
    model/output_new_filter.c
    model/output_new_pending_transaction_filter.c
    model/output_send_raw_transaction.c
    model/output_syncing.c
    model/output_uninstall_filter.c
    model/output_xlink_valid.c
    model/params_transaction.c
    model/response_block.c
    model/response_log.c
    model/response_storage_entry.c
    model/response_transaction.c
    model/response_transaction_receipt.c
    model/response_withdrawals.c
    model/sync_status.c
    api/QANAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/error_detail.h
    model/error_model.h
    model/estimate_gas_object.h
    model/filter_object.h
    model/input_call.h
    model/input_estimate_gas.h
    model/input_fee_history.h
    model/input_get_logs.h
    model/input_get_proof.h
    model/input_get_storage_at.h
    model/input_new_filter.h
    model/input_send_raw_transaction.h
    model/output_block_number.h
    model/output_call.h
    model/output_chain_id.h
    model/output_estimate_gas.h
    model/output_fee_history.h
    model/output_gas_price.h
    model/output_get_balance.h
    model/output_get_block_by_hash.h
    model/output_get_block_by_number.h
    model/output_get_block_receipts.h
    model/output_get_block_transaction_count_by_hash.h
    model/output_get_block_transaction_count_by_number.h
    model/output_get_code.h
    model/output_get_filter_changes.h
    model/output_get_filter_logs.h
    model/output_get_logs.h
    model/output_get_proof.h
    model/output_get_storage_at.h
    model/output_get_transaction_by_block_hash_and_index.h
    model/output_get_transaction_by_block_number_and_index.h
    model/output_get_transaction_by_hash.h
    model/output_get_transaction_count.h
    model/output_get_transaction_receipt.h
    model/output_max_priority_fee_per_gas.h
    model/output_new_block_filter.h
    model/output_new_filter.h
    model/output_new_pending_transaction_filter.h
    model/output_send_raw_transaction.h
    model/output_syncing.h
    model/output_uninstall_filter.h
    model/output_xlink_valid.h
    model/params_transaction.h
    model/response_block.h
    model/response_log.h
    model/response_storage_entry.h
    model/response_transaction.h
    model/response_transaction_receipt.h
    model/response_withdrawals.h
    model/sync_status.h
    api/QANAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
add_library(${pkgName} ${SRCS} ${HDRS})
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${pkgName}/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-QANAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})

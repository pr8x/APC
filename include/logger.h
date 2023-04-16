#pragma once
#include <string_view>
#include <Arduino.h>
#include <log_severity.h>
#include <config.h>

#define APC_HELPER_VA_ARGS(...) , ##__VA_ARGS__
#define APC_LOG_ERROR(fmt, ...) apc::detail::log("[ERROR] " fmt "\n", apc::log_severity::error APC_HELPER_VA_ARGS(__VA_ARGS__))
#define APC_LOG_INFO(fmt, ...) apc::detail::log("[INFO] " fmt "\n", apc::log_severity::info APC_HELPER_VA_ARGS(__VA_ARGS__))
#define APC_LOG_DEBUG(fmt, ...) apc::detail::log("[DEBUG] " fmt "\n", apc::log_severity::debug APC_HELPER_VA_ARGS(__VA_ARGS__))
#define APC_LOG_TRACE(fmt, ...) apc::detail::log("[TRACE] " fmt "\n", apc::log_severity::trace APC_HELPER_VA_ARGS(__VA_ARGS__))

namespace apc::detail {

template<class...Args>
void log(const char* format, log_severity severity, const Args&... args) {
    if (severity <= LogSeverity) {
        Serial.printf(format, args...);
    }
}

}  // namespace apc
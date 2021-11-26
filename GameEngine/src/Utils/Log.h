#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Log
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_EngineLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
private:
	static std::shared_ptr<spdlog::logger> s_EngineLogger;
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

//Engine log macros
#define ENGINE_ERROR(...)	Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_WARN(...)	Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_INFO(...)	Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_TRACE(...)	Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_FATAL(...)	Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CLIENT_ERROR(...)		Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_WARN(...)		Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_INFO(...)		Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_TRACE(...)		Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_FATAL(...)		Log::GetClientLogger()->fatal(__VA_ARGS__)


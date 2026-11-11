#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#include <ClibUtil/numeric.hpp>
#include <ClibUtil/simpleINI.hpp>
#include <ClibUtil/string.hpp>
#include <spdlog/sinks/basic_file_sink.h>
#include <xbyak/xbyak.h>

namespace logger = SKSE::log;
namespace string = clib_util::string;
namespace numeric = clib_util::numeric;

using namespace std::literals;

namespace stl
{
	using namespace SKSE::stl;

	template <class T>
	void write_thunk_call(std::uintptr_t a_src)
	{
		auto& trampoline = SKSE::GetTrampoline();
		T::func = trampoline.write_call<5>(a_src, T::thunk);
	}
}

#define OFFSET(se, ae) REL::Relocate(se, ae)

namespace Version
{
	inline constexpr auto NAME = "1.4.1"sv;
	inline constexpr auto PROJECT = "ImmersiveActivate"sv;
}

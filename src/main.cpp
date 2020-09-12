
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201703L


#include <iomanip>

#include "raffer/regex/call/call_std.hpp"
#include "../../cpp11/include/raffer/system/system.hpp"

//#include <fcntl.h>
//#include <io.h>


using Char = wchar_t;

auto std_func = raffer::unordered_functions<Char>
{
	{ raffer::to_basic_string<Char>("std::basic::func::ignore"), raffer::std_basic_func_ignore<Char> },
	{ raffer::to_basic_string<Char>("std::basic::func::if"), raffer::std_basic_func_if<Char> },
	{ raffer::to_basic_string<Char>("std::basic::func::system"), raffer::std_basic_func_system<Char> },
	{ raffer::to_basic_string<Char>("std::inout::func::print"), raffer::std_basic_func_print<Char> },
	{ raffer::to_basic_string<Char>("std::inout::func::fprint"), raffer::std_basic_func_fprint<Char> },
	
	{ raffer::to_basic_string<Char>("std::math::func::rm[-\\+]"), raffer::std_math_func_rmsign<Char> },
	{ raffer::to_basic_string<Char>("std::basic::func::arg1"), raffer::std_basic_func_arg1<Char> },
	
	{ raffer::to_basic_string<Char>("std::math::const::pi"), raffer::std_math_const_pi<Char> },
	{ raffer::to_basic_string<Char>("std::math::const::e"), raffer::std_math_const_e<Char> },
	{ raffer::to_basic_string<Char>("std::phys::const::c"), raffer::std_phys_const_c<Char> },
	
	
	{ raffer::to_basic_string<Char>("std::math::func::pow"), raffer::std_math_func_pow<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::root"), raffer::std_math_func_root<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::log"), raffer::std_math_func_log<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::mult"), raffer::std_math_func_mult<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::div"), raffer::std_math_func_div<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::mod"), raffer::std_math_func_mod<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::add"), raffer::std_math_func_add<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::sub"), raffer::std_math_func_sub<Char> },
	
	{ raffer::to_basic_string<Char>("std::logic::const::true"), raffer::std_logic_const_true<Char> },
	{ raffer::to_basic_string<Char>("std::logic::const::false"), raffer::std_logic_const_false<Char> },
	
	{ raffer::to_basic_string<Char>("std::logic::func::not"), raffer::std_logic_func_not<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::and"), raffer::std_logic_func_and<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::or"), raffer::std_logic_func_or<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::nand"), raffer::std_logic_func_nand<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::nor"), raffer::std_logic_func_nor<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::xor"), raffer::std_logic_func_xor<Char> },
	{ raffer::to_basic_string<Char>("std::logic::func::xnor"), raffer::std_logic_func_xnor<Char> },
	
	{ raffer::to_basic_string<Char>("std::basic::func::range"), raffer::std_basic_func_range<Char> },
	
	{ raffer::to_basic_string<Char>("std::math::func::floor"), raffer::std_math_func_floor<Char> },
	{ raffer::to_basic_string<Char>("std::math::func::ceil"), raffer::std_math_func_ceil<Char> },
	
	{ raffer::to_basic_string<Char>("std::math::func::sin"), raffer::std_math_func_sin<Char> },
};

auto main() -> int
{
	raffer::enable_unicode_stdio();
	
	auto func = raffer::ordered_functions<Char>(40);
	
	raffer::function_body_ptr<Char> std_func_func =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			unsigned p;
			std::basic_stringstream<Char>(arg.str(1)) >> p;
			func.at(p)[arg.str(2)] = arg.str(3);
			return raffer::to_basic_string<Char>("/*TODO*/");
		};
	
	raffer::function_body_ptr<Char> std_func_func_std =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			unsigned p;
			std::basic_stringstream<Char>(arg.str(1)) >> p;
			func.at(p)[arg.str(2)] = std_func[arg.str(3)];
			return arg.str(2);
		};
	
	raffer::function_body_ptr<Char> std_func_cmd =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			return raffer::call<Char>(arg.str(1), func, raffer::basic_smatch<Char>{});
		};
	
	raffer::function_body_ptr<Char> std_func_run =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			/*FILE * file = _wfopen(arg.str(1).c_str(), L"r");
			_setmode(_fileno(file), _O_U8TEXT);
			fseek(file, 0, SEEK_END);
			auto chars = ftell(file);
			fseek(file, 0, SEEK_SET);
			auto script = (Char*)calloc(chars, sizeof(Char));
			fread(script, sizeof(Char), chars, file);
			fclose(file);
	
			return raffer::call<Char>(script, func, raffer::basic_smatch<Char>{});*/
			
			return raffer::to_basic_string<Char>("std_func_run");
		};
	
	raffer::function_body_ptr<Char> std_basic_statement =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			return raffer::call<Char>(arg.str(1), func, raffer::basic_smatch<Char>{});
		};
	
	
	raffer::function_body_ptr<Char> std_basic_func_printall =
		[&func](raffer::basic_smatch<Char> const & arg) -> std::basic_string<Char>
		{
			for (unsigned i = 0; i < func.size(); ++ i)
				for (const auto& [name, body] : func.at(i))
				{
					raffer::basic_cout<Char> << std::right << std::setw(3) << i << " | " << std::left << std::setw(50) << name << " | ";
					try
					{
						raffer::basic_cout<Char> << std::get<std::basic_string<Char>>(body);
					}
					catch (const std::bad_variant_access&)
					{
						raffer::basic_cout<Char> << "std::function";
					}
					raffer::basic_cout<Char> << std::endl;
				}
			return raffer::to_basic_string<Char>("/*TODO*/");
		};
	
	func.at(4).insert({ raffer::to_basic_string<Char>(LR"(PRIORITY\s*(\d+)\s*(\S+)\s*IS\s*(.+))"), std_func_func });
	func.at(4).insert({ raffer::to_basic_string<Char>(LR"(PRIORITY\s*(\d+)\s*(\S+)\s*IS\s*(std::\S+))"), std_func_func_std });
	//func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*IS\s*([^\n]+))", std_func_func }); //boost
	//func.at(4).insert({ LR"(PRIORITY\s*(\d+)\s*(\S+)\s*IS\s*(std::\S+))", std_func_func_std }); //boost

	func.at(5).insert({ raffer::to_basic_string<Char>("run\\s*\"([^\"]*)\""), std_func_run });
	func.at(25).insert({ raffer::to_basic_string<Char>("print\\s*all"), std_basic_func_printall });
	
	auto stdlib_path = raffer::to_basic_string<Char>("std");
	
	#ifdef DEBUG
		raffer::basic_cout<Char> << "<<< " <<
	#endif // DEBUG
	raffer::call<Char>(raffer::to_basic_string<Char>(R"(run ")") + stdlib_path + raffer::to_basic_string<Char>(R"(/core.regs")"), func, raffer::basic_smatch<Char>{});
	
	#ifdef DEBUG
		std_basic_func_printall(raffer::basic_smatch{});
	#endif // DEBUG
	
	while (true)
	{
		std::fflush(stdin);
		raffer::basic_cout<Char> << ">>> ";
		std::basic_string<Char> input;
		while (!std::getline(raffer::basic_cin<Char>, input));
		raffer::basic_cout<Char> << "<<< " << raffer::call<Char>(input, func, raffer::basic_smatch<Char>{}) << std::endl;
	}
}


#endif // __cplusplus >= 201703L

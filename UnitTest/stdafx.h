// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#ifndef _UNIT_TEST_H
#define _UNIT_TEST_H

#include <string>
#include <sstream>
#include <cassert>
#include <exception>
#include <iostream>

//#include "targetver.h"

using std::string;

namespace UnitTest {
	class TestRunner {
	private:
		int fail_count = 0;
	public:
		template <typename TestFunc> void RunTest(TestFunc func, const string& TestName) {
			try {
				func();
				std::cerr << TestName << " OK" << std::endl;
			}
			catch (const std::exception& excp) {
				fail_count++;
				std::cerr << TestName << " fail: " << excp.what() << std::endl;
			}
		}

		~TestRunner() {
			if (fail_count > 0) {
				std::cerr << fail_count << " tests failed. Terminate";
				//std::exit(1);
			}
		}
	};

	template<typename T, typename U> void AssertEqual(const T& lhs, const U& rhs, const string& hint) {
		if (lhs != rhs) {
			std::ostringstream os;
			os << "Assertion failed: " << lhs << " != " << rhs << " Hint: " << hint;
			throw std::runtime_error(os.str());
		}
	}
	template<typename T, typename U> void AssertLess(const T& lhs, const U& rhs, const string& hint) {
		if (lhs > rhs) {
			std::ostringstream os;
			os << "Assertion failed: " << lhs << " > " << rhs << " Hint: " << hint;
			throw std::runtime_error(os.str());
		}
	}
	template<typename T, typename U> void AssertMore(const T& lhs, const U& rhs, const string& hint) {
		if (lhs < rhs) {
			std::ostringstream os;
			os << "Assertion failed: " << lhs << " < " << rhs << " Hint: " << hint;
			throw std::runtime_error(os.str());
		}
	}

	void Assert(bool b, const string& hint) {
		AssertEqual(b, true, hint);
	}

}
#endif // !_UNIT_TEST_H#pragma once


// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы

I am providing code in the repository to you under [an open source license](LICENSE).
Because this is my personal repository, the license you receive to my code is
from me and not my employer (Facebook).

Warning
=
This project is C++ "stunt coding": an exercise in finding out if I could do this.

If you are looking to produce formatted output in a real program I recommend
you use [the idiomatic C++ mechanism](https://en.cppreference.com/w/cpp/io/basic_ostream)
or [the idiomatic C mechanism](https://en.cppreference.com/w/cpp/io/c/fprintf).

What is this?
=
This is a suite of `constexpr` format function objects in standard C++17 and a
printf-alike user-defined string literal suffix that's implemented with a
nonstandard GCC/LLVM C++ extension.

What does printf-alike mean?
-
`%` is the special character that means to insert some formatting. The valid
format characters are a bit different. Length modifiers (`hh`, `h`, `l`, `ll`)
are never used because C++ allows us to detect the type of the argument.

The valid format charaters right now are:

| Character | Description |
|-----------|--------------
| `%` | A literal percent character. No argument. |
| `d` | Print an integer argument as decimal. Accepts any signed or unsigned integer type. Replaces `d`, `i`, `u`. |
| `x` | Print an integer argument as lowercase hexadecimal. Accepts any unsigned integer type. Replaces `x`. |
| `X` | Print an integer argument as uppercase hexadecimal. Accepts any unsigned integer type. Replaces `X`. |
| `s` | Print a string argument. Accepts std::basic_string_view of the same character type as the format string and chacter pointers to NULL-terminated (c-style) strings. Replaces `s`. |

Is it functionally complete?
-
No. Notably there is no support for rendering floating point numbers, padding
or aligning fields, or setting the formatted precision.

Are there any other limitations?
-
You can probably hit your environment's limits for number of superclasses,
number of template parameters, maximum length of a function name, etc.

Usability
-
If you get anything wrong (wrong argument type, extra arguments, missing
arguments, etc) you can expect screens of nested template errors, none of
which really tell you what you did wrong.

Performance
-
In [realistic benchmarks](examples/RuntimeBenchmarks.cpp) it's comparable to
C++'s `ofstream` and slower than C's `fprintf`. In [unrealistic benchmarks](examples/StaticBenchmarks.cpp)
it's faster than both, but that's not relevant.
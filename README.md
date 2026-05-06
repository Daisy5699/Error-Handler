## aurelia - error handler lib (header-file only)
- _simple error handler with a templated class, extremely simple honestly just made this for fun._
- _not much information to go over so yeah enjoy._

## usage example
```c++
#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>

utility::c_error<int> divide ( int a , int b )
{
	if (b == 0) { return utility::c_error< int >("division by 0", __FILE__, __LINE__); }
	return a / b;
}

std::int32_t main(int argc, const char* argv[])
{
	std::ios_base::sync_with_stdio(false);

	SetConsoleTitleA("aurelia-eh-debug");
	
	std::println("made by: daisy");

	auto outcome = divide(5, 2);
	if (outcome.is_error())
	{
		std::println("cannot divide by 0, exiting -> %s", outcome.has_msg().c_str());
		return 0;
	}
	std::println("division is correct, continuing to getting value");

	if (outcome.get())
	{
		std::println("failed to get outcome value.", outcome.get());
	}
	std::println("successfully got outcome value -> 0x%p", outcome.get());

	std::cin.ignore();
	std::cin.get();
}

```
- **_simple example for using this, code is pretty clean i'll definitely expand on this in the future and make it more 
  advanced_**.

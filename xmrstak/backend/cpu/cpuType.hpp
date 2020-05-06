#pragma once

#include <cstdint>
#include <string>

namespace xmrstak
{
namespace cpu
{
struct Model
{
	uint32_t family = 0u;
	uint32_t model = 0u;
	bool aes = false;
	bool sse2 = false;
	bool avx = false;
	std::string type_name = "unknown";
	std::string name;
};

Model getModel();

/** Mask bits between h and l and return the value
	 *
	 * This enables us to put in values exactly like in the manual
	 * For example EBX[30:22] is get_masked(cpu_info[1], 31, 22)
	 */
int32_t get_masked(int32_t val, int32_t h, int32_t l);

bool firstHasBMI2();

inline bool hasBMI2()
{
	static bool bmi2 = firstHasBMI2();
	return bmi2;
}

} // namespace cpu
} // namespace xmrstak

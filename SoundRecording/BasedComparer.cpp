#include "BasedComparer.h"

namespace Music
{
	namespace Categorization
	{
		template <class ComapredType, class FunctionInput>
		bool BasedComparer<ComapredType, FunctionInput>::operator()(ComparingPtrType a, ComparingPtrType b) const
		{
			return func_(GetInput(a), GetInput(b));
		}
	}
}
#pragma once
namespace Music
{
	namespace Categorization
	{
		template <class ComapredType, class FunctionInput>
		class BasedComparer
		{
		public:
			using FunctionInputType = const FunctionInput&;
			using ComparingType = ComapredType;
			using ComparingPtrType = const ComapredType* const;
			using CompareFunction = bool (*)(const FunctionInput& a, const FunctionInput& b);

			BasedComparer(CompareFunction func) : func_(func) {}

			bool operator()(ComparingPtrType a, ComparingPtrType b) const;

		protected:
			virtual FunctionInputType GetInput(ComparingPtrType ptr) const = 0;

		private:
			CompareFunction func_;
		};
	}
}


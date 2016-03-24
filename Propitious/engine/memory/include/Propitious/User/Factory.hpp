#ifndef PROPITIOUS_USER_FACTORY_HPP
#define PROPITIOUS_USER_FACTORY_HPP

#include <Propitious/Containers/Hashmap.hpp>
#include <Propitious/Math/Hash.hpp>

namespace Propitious
{
	namespace Factory
	{
		typedef void* (*ClassReferenceFunction)();

		extern HashMap<ClassReferenceFunction> classReferences;

#define LINK_CLASS_TO_NAME(classname, classReference)																									\
			void* classReference##FUNCTION()																											\
			{																																			\
				return new classReference##();																											\
			}																																			\
			class classReference##FACTORY																												\
			{																																			\
				public:																																	\
				classReference##FACTORY()																												\
				{																																		\
					set(Factory::classReferences, hash(classname##), &classReference##FUNCTION);														\
				}																																		\
			};																																			\
			static classReference##FACTORY classReference##FACTORYINSTANCE;

		template <typename T>
		T& create(const char* classname)
		{
			return get(classReferences, hash(classname));
		}

	}
}



#endif
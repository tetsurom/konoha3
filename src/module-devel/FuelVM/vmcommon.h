#include <stdint.h>
#include <stdbool.h>
#include "../../../include/minikonoha/minikonoha.h"

#ifndef VMCOMMON_H
#define VMCOMMON_H

enum TypeId {
	TYPE_void = KType_void,
	TYPE_boolean = KType_boolean,
	TYPE_int = KType_int,
	TYPE_String = KType_String,
	TYPE_Function = KType_Func,
	TYPE_Array = KType_Array,
	TYPE_Method = KType_Method,
	TYPE_NameSpace = KType_NameSpace,
	TYPE_Any = KType_0,
	TYPE_float
};

typedef union SValue {
	int64_t     ival;
	double      fval;
	bool        bval;
	void       *ptr;
	const char *str;
	uint64_t    bits;
	kObject    *obj;
} SValue;

typedef struct LObject {
	void *Header;
	SValue fields[4];
} LObject;

static inline bool IsUnBoxedType(enum TypeId Type)
{
	switch(Type) {
		case TYPE_void:
			assert(0 && "FIXME");
		case TYPE_boolean:
		case TYPE_int:
		case TYPE_float:
			return true;
		default:
			return false;
	}
}

#endif /* end of include guard */
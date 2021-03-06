//
//  native_runtime.h
//  dart_native
//
//  Created by 杨萧玉 on 2019/10/24.
//

#import "DNMacro.h"

#ifndef native_runtime_h
#define native_runtime_h

NS_ASSUME_NONNULL_BEGIN

DN_EXTERN NSMethodSignature * _Nullable
native_method_signature(Class cls, SEL selector);

DN_EXTERN void
native_signature_encoding_list(NSMethodSignature *signature, const char * _Nonnull * _Nonnull typeEncodings);

DN_EXTERN BOOL
native_add_method(id target, SEL selector, char *types, void *callback);

DN_EXTERN char * _Nullable
native_protocol_method_types(Protocol *proto, SEL selector);

DN_EXTERN Class _Nullable
native_get_class(const char *className, Class baseClass);

DN_EXTERN void * _Nullable
native_instance_invoke(id object, SEL selector, NSMethodSignature *signature, dispatch_queue_t queue, void * _Nonnull * _Nullable args, BOOL waitUntilDone);

DN_EXTERN void *
native_block_create(char *types, void *callback);

DN_EXTERN void *
native_block_invoke(void *block, void * _Nonnull * _Nullable args);

DN_EXTERN const char *
native_type_encoding(const char *str);

DN_EXTERN const char * _Nonnull * _Nullable
native_types_encoding(const char *str, int * _Nullable count, int startIndex);

DN_EXTERN const char * _Nullable
native_struct_encoding(const char *encoding);

DN_EXTERN bool
LP64(void);

DN_EXTERN bool
NS_BUILD_32_LIKE_64(void);

DN_EXTERN dispatch_queue_main_t
_dispatch_get_main_queue(void);

DN_EXTERN void
native_mark_autoreleasereturn_object(id object);

NS_ASSUME_NONNULL_END

#endif /* native_runtime_h */

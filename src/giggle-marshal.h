
#ifndef __giggle_marshal_MARSHAL_H__
#define __giggle_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:OBJECT,OBJECT (giggle-marshal.list:1) */
extern void giggle_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* STRING:OBJECT (giggle-marshal.list:2) */
extern void giggle_marshal_STRING__OBJECT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

G_END_DECLS

#endif /* __giggle_marshal_MARSHAL_H__ */


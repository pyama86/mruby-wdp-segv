/*
** mrb_wdpsegv.c - WDPSegV class
**
** Copyright (c) pyama86 2017
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_wdpsegv.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_wdpsegv_data;

static const struct mrb_data_type mrb_wdpsegv_data_type = {
  "mrb_wdpsegv_data", mrb_free,
};

static mrb_value mrb_wdpsegv_init(mrb_state *mrb, mrb_value self)
{
  mrb_wdpsegv_data *data;
  char *str;
  int len;

  data = (mrb_wdpsegv_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_wdpsegv_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_wdpsegv_data *)mrb_malloc(mrb, sizeof(mrb_wdpsegv_data));
  data->str = str;
  data->len = len;
 // DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_wdpsegv_hello(mrb_state *mrb, mrb_value self)
{
  mrb_wdpsegv_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_wdpsegv_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_wdp_segv_gem_init(mrb_state *mrb)
{
  struct RClass *wdpsegv;
  wdpsegv = mrb_define_class(mrb, "WDPSegV", mrb->object_class);
  mrb_define_method(mrb, wdpsegv, "initialize", mrb_wdpsegv_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, wdpsegv, "hello", mrb_wdpsegv_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, wdpsegv, "hi", mrb_wdpsegv_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_wdp_segv_gem_final(mrb_state *mrb)
{
}


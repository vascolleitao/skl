#pragma once


/* Aggregate */
#include "skl/base/aggregate/index.hpp"
#include "skl/base/aggregate/simple.hpp"
#include "skl/base/aggregate/zip.hpp"
//#include "skl/base/aggregate/dummy.hpp"

/* Skeletons */
#include "skl/base/skeleton/map.hpp"
#include "skl/base/skeleton/reduce.hpp"
#include "skl/base/skeleton/filter.hpp"

/* Structure generation */
#include "skl/base/structure/decorator.hpp"
#include "skl/base/structure/aggregate.hpp"
#include "skl/base/structure/template_method.hpp"

namespace skl
{
  struct base
  {
    template<typename skeleton_t>
    auto refine_skeleton(const skeleton_t& skeleton)
    {
      return skeleton;
    }

    template<decorator_c decorator_t>
    auto refine_skeleton(const decorator_t& decorator)
    {
      return skl::decorator(
        refine_skeleton(decorator.head),
        refine_skeleton(decorator.tail));
    }

    template<template_method_c template_method_t>
    auto refine_template_method(const template_method_t& template_method)
    {
      return template_method;
    }
  };
}// namespace skl
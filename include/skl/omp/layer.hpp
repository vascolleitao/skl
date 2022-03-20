#pragma once

/* Skeletons */
#include "skl/omp/skeleton/reduce.hpp"

/* Structure generation */
#include "skl/omp/skeleton/template_method.hpp"

namespace skl::omp
{
  template<typename Super>
  struct proxy_factory : Super
  {
    template<typename Skeleton>
    static auto refine_skeleton(Skeleton skeleton)
    {
      auto s = Super::refine_skeleton(skeleton);
      return skl::omp::skeleton::proxy(s);
    }

    template<typename TemplateMethod>
    static auto refine_template_method(TemplateMethod template_method)
    {
      auto tp = Super::refine_template_method(template_method);
      return skl::omp::template_method_proxy_generate(tp);
    }
  };
}// namespace skl::omp
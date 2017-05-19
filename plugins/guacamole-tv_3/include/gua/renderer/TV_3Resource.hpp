/******************************************************************************
 * guacamole - delicious VR                                                   *
 *                                                                            *
 * Copyright: (c) 2011-2013 Bauhaus-Universität Weimar                        *
 * Contact:   felix.lauer@uni-weimar.de / simon.schneegans@uni-weimar.de      *
 *                                                                            *
 * This program is free software: you can redistribute it and/or modify it    *
 * under the terms of the GNU General Public License as published by the Free *
 * Software Foundation, either version 3 of the License, or (at your option)  *
 * any later version.                                                         *
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   *
 * for more details.                                                          *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program. If not, see <http://www.gnu.org/licenses/>.             *
 *                                                                            *
 ******************************************************************************/

#ifndef GUA_TV_3_RESOURCE_HPP
#define GUA_TV_3_RESOURCE_HPP

// guacamole headers
#include <gua/platform.hpp>
#include <gua/renderer/RenderContext.hpp>
#include <gua/renderer/GeometryResource.hpp>
#include <gua/utils/KDTree.hpp>

// external headers
#include <scm/core/math.h>

#include <scm/gl_core/gl_core_fwd.h>
#include <scm/gl_core/data_types.h>
#include <scm/gl_core/state_objects.h>
#include <scm/gl_core/texture_objects.h>

#include <scm/gl_util/primitives/box_volume.h>
#include <scm/gl_util/primitives/primitives_fwd.h>
#include <scm/gl_util/primitives/geometry.h>


#include <scm/core/platform/platform.h>
#include <scm/core/utilities/platform_warning_disable.h>


//#include <pbr/types.h>
//#include <pbr/ren/model_database.h>
//#include <pbr/ren/cut_database.h>
//#include <pbr/ren/cut.h>
//#include <pbr/ren/lod_point_cloud.h>

namespace gua {

  namespace node{
    class TV_3Node;
  };

/**
 * Stores a point cloud model with LOD.
 *
 * This class simply a wrapper for accessing models of PBR library
 */
class TV_3Resource : public GeometryResource {
 
  public: // c'tor /d'tor

    TV_3Resource(std::string const& resource_file_string, bool is_pickable);

    ~TV_3Resource();

  public: // methods
    
    /*virtual*/ void draw(RenderContext const& context) const;


    /**
     * Draws the point cloud.
     *
     * Draws the point cloud to the given context.
     *
     * \param context  The RenderContext to draw onto.
     */

    //dummy
    void draw(RenderContext const& ctx,
              scm::gl::vertex_array_ptr const& vertex_array) const;

    void bind_volume_texture(RenderContext const& ctx, scm::gl::sampler_state_ptr const& sampler_state) const;
    math::mat4 const& local_transform() const;

    void upload_to(RenderContext const& context) const;

    void ray_test(Ray const& ray,
                  int options,
                  node::Node* owner,
                  std::set<PickResult>& hits);

 private:
  //std::shared_ptr<*/scm::gl::box_volume_geometry> volume_proxy_;
  bool                                 is_pickable_;
  math::mat4                           local_transform_;
  mutable scm::gl::texture_3d_ptr      volume_texture_;

  std::string                          resource_file_name_;
};

}

#endif  // GUA_PLOD_RESSOURCE_HPP

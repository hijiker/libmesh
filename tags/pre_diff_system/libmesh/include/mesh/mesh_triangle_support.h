// $Id: mesh_triangle_support.h,v 1.4 2005-10-13 16:36:31 roystgnr Exp $
 
// The libMesh Finite Element Library.
// Copyright (C) 2002  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


#ifndef __mesh_triangle_support_h__
#define __mesh_triangle_support_h__

#include "libmesh_config.h"

#ifdef HAVE_TRIANGLE

// Note: libmesh_common.h defines REAL, which is required by triangle.
// Therefore, we need to include it first.
#include "libmesh_common.h"

typedef Real REAL;

/**
 * A special namespace for wrapping the standard Triangle API,
 * as well as some helper functions for initializing/destroying
 * the structs triangle uses to communicate.
 */
namespace Triangle {
extern "C" {
#include "triangle.h"
}

  /**
   * Initializes the fields of t to NULL/0 as necessary.
   * This is helpful for preventing the access of uninitialized
   * memory when working with C, which has no constructors or
   * destructors.
   */
  void init(triangulateio& t);
    
  /**
   * Frees any memory which has been dynamically allocated by
   * Triangle.  This is safe due to the fact that 1) Triangle does
   * not free any memory itself, and 2) it is safe to call free
   * on the NULL pointer.
   */
  void destroy(triangulateio& t);
}










// // Forward declarations
// class Mesh;

// /**
//  * This class is used to hide the details of the interaction
//  * with the C library Triangle, and to translate the results
//  * of its triangulations into libMesh meshes.
//  *
//  * @author John W. Peterson, 2005
//  */
// class TriangleMeshInterface
// {
// public:
//   /**
//    * Constructor, obviously the mesh reference must be
//    * non-const since we are going to construct it!
//    */
//   TriangleMeshInterface(Mesh& mesh);

//   /**
//    * Destructor.
//    */
//   ~TriangleMeshInterface() {}

//   /**
//    * Constructs a triangulation of the nodes in the current
//    * mesh.  Any existing elements are ignored during
//    * the triangulation and deleted to make room for the new
//    * triangles upon completion.  Depending on the parameters
//    * passed to the triangulate routine, nodes may be added as
//    * well.  Therefore you should not rely on any previous
//    * nodes or elements which were in your mesh after calling
//    * this function.
//    */
//   void triangulate ();
  
// protected:
//   Mesh& _mesh;
// };




#endif // HAVE_TRIANGLE

#endif
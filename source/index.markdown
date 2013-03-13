---
layout: page
title: Data Analysis at Extreme
date: 2013-03-10 11:55
comments: false
sharing: false
footer: false
---

The Dax Toolkit is an open source C++ header only library that provides a collection of data analysis and visualization algorithms that run well on multi- and many-core processors.  The Dax Toolkit also makes it easy to design other visualization algorithms that work well on such processors. We currently support CUDA, OpenMP, Intel TBB, and Serial Execution.


### How ###

The Dax Toolkit uses fine-grained concurrency for data analysis and visualization algorithms.
The basic computational unit of the Dax Toolkit is a worklet, a function that implements the algorithm’s behavior on an element of a mesh (that is, a point, edge, face, or cell) or a small local neighborhood.

The worklet is constrained to be serial and stateless; it can access only the element passed to and from the invocation. With this constraint, the serial worklet function can be concurrently scheduled on an unlimited number of threads without the complications of threads or race conditions.

Although worklets are not allowed communication, many visualization algorithms require operations such as variable array packing and coincident topology resolution that intrinsically require significant coordination among threads. Dax enables such algorithms by classifying and implementing the most common and versatile communicative operations into worklet types which are managed by the Dax scheduler.

### Why ###


The Dax Toolkit simplifies the development of parallel visualization algorithms. Consider the computation of gradients using finite differences. Because the Dax Toolkit is structured such that it can schedule its execution on a GPU, we measure that it performs this operation over 100 times faster than VTK running on a single CPU. Furthermore, the Dax API can be switched to a different device by changing only a single line of code. Dax currently provides scheduling for CUDA (GPU), OpenMP (multicore CPU), and serial execution.

{% include_code lang:cpp Gradient.worklet %}

## Getting Dax ##


The Dax repository is located at [https://github.com/kitware/DaxToolkit](https://github.com/kitware/DaxToolkit)

Dax dependencies are:


+  [CMake 2.8.8](http://cmake.org/cmake/resources/software.html)
+  [Boost 1.49.0](http://www.boost.org) or greater
+  [Cuda Toolkit 4+](https://developer.nvidia.com/cuda-toolkit) or [Thrust 1.4 / 1.5](https://thrust.github.com)
   depending if you want Cuda and/or OpenMP

```
git clone git://github.com/Kitware/DaxToolkit.git dax
mkdir dax-build
cd dax-build
cmake-gui ../dax
```

A detailed walk-through of installing and building Dax can be found on our [Install page](/install/)


## Example ##


This basic worklet finds the magnitude of a vector

{% include_code lang:cpp Magnitude.worklet %}

And here is how to execute the worklet:

{% include_code lang:cpp Magnitude.cpp %}

More examples can be found on our [Use page](/use/)


## Publications ##


[Flexible Analysis Software for Emerging Architectures](http://www.sandia.gov/~kmorel/documents/DaxPDAC2012). Kenneth Moreland, Brad King, Robert Maynard, and Kwan-Liu Ma. In ''Petascale Data Analytics: Challenges and Opportunities (PDAC-12), November 2012.

[Dax Toolkit: A Proposed Framework for Data Analysis and Visualization at Extreme Scale](http://www.sandia.gov/~kmorel/documents/DaxLDAV2011.pdf). Kenneth Moreland, Utkarsh Ayachit, Berk Geveci, and Kwan-Liu Ma. In ''IEEE Symposium on Large-Scale Data Analysis and Visualization (LDAV), October 2011.

 [Dax: Data Analysis at Extreme](http://www.sandia.gov/~kmorel/documents/SciDAC2011-Dax.pdf). Kenneth Moreland, Utkarsh Ayachit, Berk Geveci, and Kwan-Liu Ma. In ''Proceedings of SciDAC 2011'', July 2011.


## Contacts ##

Kenneth Moreland  
Sandia National Laboratories  
kmorel@sandia.gov  

Robert Maynard  
Kitware, Inc.  
robert.maynard@kitware.com  

Berk Geveci  
Kitware, Inc.  
berk.geveci@kitware.com  

Kwan-Liu Ma  
University of California at Davis  
ma@cs.ucdavis.edu  


## License ##

Copyright (c) Kitware, Inc.  
All rights reserved.  
[See LICENSE.txt for details](https://github.com/Kitware/DaxToolkit/blob/master/LICENSE.txt).  

Copyright 2011 Sandia Corporation.  
Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,  
the U.S. Government retains certain rights in this software.  


This software is distributed WITHOUT ANY WARRANTY; without even  
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
[See the copyright file for more information](https://github.com/Kitware/DaxToolkit/blob/master/LICENSE.txt).  


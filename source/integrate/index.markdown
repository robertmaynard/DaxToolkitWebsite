---
layout: page
title: "How to Integrate Dax into your project"
date: 2013-03-10 12:07
comments: false
sharing: false
footer: false
---

Using Dax from your own project is easy, especially if you use CMake for your project.
This page provides some basic documentation to get you up and running with Dax.

Before beginning with these instructions, please have Dax already somewhere on your system.
If you want to download the source and configure it especially for your system,
A detailed walk-through of installing and building Dax can be found on our [Install page](/install/).

## Basic CMake setup ##

Let us say that we start with an empty directory in which we are going to create a project that relies on Dax.
We first create a CMakeLists.txt that defines the project.
Here is a simple CMakeLists.txt that defines the project, finds and configures Dax, and creates targets to build a program.

{% include_code lang:cmake integrateBasicCMakeLists.txt %}

I've commented the CMake configuration to make it easy to follow what each of these steps does.
This particular configuration compiles Dax for OpenMP, but we will get to a CUDA example in a little bit.

To complete the example, here is an example of ex1.cxx, a very simply program that creates a mesh and runs a parallel operation on it.

{% include_code lang:cpp integrateBasic.cpp %}

## Set up a CUDA build and other CMake options ##

Setting up a CUDA build is not much different than setting up an OpenMP build like the one shown above.  The only real differences are calling DaxConfigureCuda instead of DaxConfigureOpenMP and using the special commands for compiling cuda (e.g. cuda_add_executable in place of add_executable).  The following CMakeLists.txt extends the previous one to add a CUDA compile and also demonstrate some other miscellaneous features.

{% include_code lang:cmake integrateCudaCMakeLists.txt %}

In addition to showing how to build a CUDA program with Dax, we also demonstrated how to detect when a particular Dax configuration is not available (for example, if CUDA could not be found on your computer) and alter the build accordingly.  If we wanted to force the configuration to use CUDA or fail, we could simply have REQUIRED the CUDA configuration.

``` cmake
DaxConfigureCuda(REQUIRED)
cuda_add_executable(daxexample_cuda ${CMAKE_BINARY_DIR}/ex1.cu)
```

## Using other build systems ##

We have made it as easy as possible to use Dax with CMake, but it is straightforward to use Dax with other build systems as well.  Dax is really just a header file library, so using Dax is as simply as pointing your compiler to the include directory where Dax is installed.  (We do not recommend trying to link a project to the Dax source without CMake.  It is more complicated.)

Of course, you will still have to find and configure Dax's dependent libraries (such as Boost, Thrust, OpenMP, and CUDA).  That will be up to your independent build system.

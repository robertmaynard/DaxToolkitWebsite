---
layout: page
title: "Building and Installing Dax"
date: 2013-03-10 12:07
comments: false
sharing: false
footer: false
---

Dax is currently available from both github and kitware. Both repositories have public anonymous read only access.  

1.  [http://public.kitware.com/DaxToolkit.git](http://public.kitware.com/DaxToolkit.git)
2.  [https://github.com/Kitware/DaxToolkit.git](https://github.com/Kitware/DaxToolkit.git)


If you haven't used git before I recommend following [github's excellent setup guide](https://help.github.com/articles/set-up-git). Both repo's support cloning using the http and git protocol. Push access is only allowed with the SSH protocol. If you want to contribute to Dax please read the Submitting Patches section. If you are wish to be a core developer of Dax please send your public SSH key to [Kitware](https://www.kitware.com/Admin/SendPassword.cgi).

## Dependencies ##

+  [CMake 2.8.8](http://cmake.org/cmake/resources/software.html)
   To build the Dax testing framework you need a relatively new version of CMake
   We recommend 2.8.10 but support back to 2.8.8
+  [Boost 1.49.0](http://www.boost.org) or greater
   We only require that you install the header components of Boost
+  [Cuda Toolkit 4+](https://developer.nvidia.com/cuda-toolkit) or [Thrust 1.4 / 1.5](https://thrust.github.com)
   For the CUDA backend you will need at least the CudaToolkit 4 and the corresponding device driver. If you don't have a NVidia graphics card and want to use OpenMP acceleration, you will need Thrust version 1.4 or 1.5. We currently haven't tested with Thrust 1.6

## Supported OSes ##
We currently only support Linux and Mac OSX. We are currently working on
Windows support, and hope to have it finished 'soon'.

## Building ##
While the Dax toolkit is header only, the repository includes a large testing framework that needs to be built. Building Dax will verify that you have enabled the correct options, and is a great resource for how to develop your own Dax worklets.

Always configure Dax so that the build tree is not in the source directory. The project will not run if you setup the source and build directories to be the same directory.

A basic guide to setting up dax:

```
git clone git://github.com/Kitware/DaxToolkit.git dax
mkdir dax-build
cd dax-build
cmake-gui ../dax
make
make test
```

(Note that parallel makes are supported, so you can run something like <tt>make -j4</tt> to take advantage of multiple cores during the build.)

### Dax CMake Settings ###

| Variable | Description |
| -------- | ----------- |
| DAX_ENABLE_CUDA | Turn this to ON to enable the CUDA backend to Dax. This requires the Cuda Toolkit and Thrust.
| DAX_ENABLE_OPENMP | Turn this to ON to enable the OpenMP backend to Dax. This requires Thrust
| DAX_ENABLE_TESTING | Turn on building the Header tests, Unit tests, and Benchmark tests.
| DAX_USE_64BIT_IDS | Enable 64bit Id support. Dax can only be 32bit or 64bit it doesn't support mixing of the types. Using this with the Cuda backend generally requires a tesla card.
| DAX_USE_DOUBLE_PRECISION | Enable using double as the representation type for dax::Scalar. Using this with the Cuda backend generally requires a tesla card.


### Using Other Build System ###
We have made it as easy as possible to use Dax with CMake, but it is straightforward to use Dax with other build systems as well. Dax is really just a header file library, so using Dax is as simply as pointing your compiler to the include directory where Dax is installed. Of course, you will still have to find and configure Dax's dependent libraries (such as Boost, Thrust, OpenMP, and CUDA). That will be up to your independent build system.

## Documentation ##

We are currently in the progress of writing doxygen for all the classes in Dax. You can find the current documentation at:
  http://www.daxtoolkit.org/Doc/classes.html

## Submitting Patches ##

Currently the Dax repository only allows the core team of developers push access. We are going to experiment and try out the GitHub
Fork & Pull model of development.

The Fork & Pull model of development is simple:
+  Fork the Dax project on GitHub (https://github.com/Kitware/DaxToolkit)
+  Modify the project however you want, we recommend creating a topic branch for your changes so that the pull request stays up to date with any changes that are needed.
+  Submit a pull request to the Dax development team from your forked github webpage (click the pull request button).
+  Once the pull request is received by the development team we will comment on the request, and work with you to get the changes merged in.

More information on the Fork & Pull development model is at: https://help.github.com/articles/using-pull-requests

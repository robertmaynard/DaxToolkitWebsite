---
layout: page
title: "install"
date: 2013-03-10 12:07
comments: true
sharing: true
footer: true
---

UNDER DEV

Dax is an open source C++ header only toolkit that provides
the ability to do fine-grained concurrency on scientific visualization data structures. We currently support
running in parallel on CUDA supported graphics cards, and on the CPU using OpenMP.

==Getting Dax==
Dax is currently available from both github and kitware. Both repositories have public anonymous read only access.

  http://public.kitware.com/DaxToolkit.git
  https://github.com/Kitware/DaxToolkit.git

If you haven't used git before I recommend following github's excellent setup guide (https://help.github.com/articles/set-up-git). Both repo's
support cloning using the http and git protocol. Push access is only allowed with the SSH protocol. If you want to contribute to Dax please
read the [[#Submitting Patches|Submitting Patches]] section. If you are a core developer of Dax please use this [https://www.kitware.com/Admin/SendPassword.cgi link] to send your public SSH key to Kitware.

==Dependencies==

* CMake: To build the Dax testing framework you need a  relatively new version of CMake. CMake 2.8.8 or newer is recommended.
*Boost 1.48.0: To use Dax you only need the header version, but to test Dax you do need the libraries.
*Cuda Toolkit 4+: For the CUDA backend you will need at least the CudaToolkit 4 and the corresponding device driver.
** If you don't have a NVidia graphics card you can still use the OpenMP acceleration by installing Thrust. You will need Thrust version 1.4 or 1.5. We currently haven't tested with Thrust 1.6

==Supported OSes==
We currently only support Linux and Mac OSX. If you need Windows support we have an experimental branch called 'WindowsSupport' which you can try.

==Building Dax With CMake==
While the Dax toolkit is header only, the repository includes a large testing framework that needs to be built. Building Dax will verify that you have enabled the correct options, and is a great resource for how to develop your own Dax worklets.

Always configure Dax so that the build tree is not in the source directory. The project will not run if you setup the source and build directories to be
mixed.

A basic guide to setting up dax:
 git clone https://github.com/Kitware/DaxToolkit.git
 mkdir DaxBuild
 cd DaxBuild && cmake-gui ../DaxToolkit
 make
 make test

(Note that parallel makes are supported, so you can run something like <tt>make -j4</tt> to take advantage of multiple cores during the build.)

===Dax CMake Settings===

{| border="0" cellpadding="4" cellspacing="4"
|-
| bgcolor="#abcdef" height="8" |  '''Variable'''
| bgcolor="#abcdef" height="8" |  '''Description'''
|-
| DAX_ENABLE_CUDA || Turn this to ON to enable the CUDA backend to Dax. This requires the Cuda Toolkit and Thrust.
|-
| DAX_ENABLE_OPENMP || Turn this to ON to enable the OpenMP backend  to Dax. This requires Thrust, and compiler that has openMP support ( not Clang )
|-
| DAX_ENABLE_TESTING || Turn on building the Header tests, Unit tests, and Benchmark tests.
|-
| DAX_USE_64BIT_IDS || Enable 64bit Id support. Dax can only be 32bit or 64bit it doesn't support mixing of the types. Using this with the Cuda backend generally requires a tesla card.
|-
| DAX_USE_DOUBLE_PRECISION || Enable using double as the representation type for dax::Scalar. Using this with the Cuda backend generally requires a tesla card.
|-
|}


=== Using Other Build System ===
We have made it as easy as possible to use Dax with CMake, but it is straightforward to use Dax with other build systems as well. Dax is really just a header file library, so using Dax is as simply as pointing your compiler to the include directory where Dax is installed. Of course, you will still have to find and configure Dax's dependent libraries (such as Boost, Thrust, OpenMP, and CUDA). That will be up to your independent build system.

==Documentation==

We are currently in the progress of writing doxygen for all the classes in Dax. You can find the current documentation at:
  http://www.daxtoolkit.org/Doc/classes.html

==Submitting Patches==

Currently the Dax repository only allows the core team of developers push access. We are going to experiment and try out the GitHub
Fork & Pull model of development.

The Fork & Pull model of development is simple:
# Fork the Dax project on GitHub (https://github.com/Kitware/DaxToolkit)
# Modify the project however you want, we recommend creating a topic branch for your changes so that the pull request stays up to date with any changes that are needed.
# Submit a pull request to the Dax development team from your forked github webpage (click the pull request button).
# Once the pull request is received by the development team we will comment on the request, and work with you to get the changes merged in.


More information on the Fork & Pull development model is at: https://help.github.com/articles/using-pull-requests

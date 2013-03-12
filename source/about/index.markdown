---
layout: page
title: "About"
date: 2013-03-10 12:07
comments: false
sharing: false
footer: false
---

Whereas supercomputers throughout the terascale era were almost unilaterally built
from general purpose CPU processors on distributed memory nodes with a message passing
interface, in petascale computing we are seeing the emerging use of accelerators to meet the execution and computation
requirements of modern leadership-class facilities. This trend was kicked off when the Roadrunner supercomputer, ﬁrst to
achieve a petaFLOP, was built with Cell BE processors. At the time, Roadrunner was an anomaly, but since then many
high-performance computers followed this example. Today, over 12% of the Top 500 supercomputers, including the top
performing system, Titan, incorporate accelerators, and that number is growing.


These accelerators represent a significant departure from how we most often perform parallel processing. Computing
on the previous generation of high performance computers involved partitioning data among distributed memory nodes
and running independent processes that pass messages. However, accelerators do not work well with such an approach.
Threads on an accelerator may be grouped in SIMD “warps”, can have indeterminate scheduling, and may be incapable of
direct message passing. Even on processors with more complete and independent cores, taking advantage of shared
memory threads can have its advantages. Ultimately, our algorithms must exhibit a more “pervasive parallelism”
comprising a marked increase in concurrency and careful data management.


Another problem facing current research and development is the shifting landscape of the development environment.
The Cell BE processors (and associated compiler environment) comprising Roadrunner is already discontinued. Instead,
NVIDIA is aggressively pursing leadership in accelerator technology for scientific computation with Intel hot on its
heels. Several compiler technologies such as OpenMP, CUDA, Intel Threading Building Blocks, and OpenACC also compete
for multi-threaded programming. Our team is creating the Dax toolkit, which seeks to provide a development framework for scientific data analysis
and visualization algorithms for the next generation of high performance computers and beyond. In this paper we document the following features.

1. A general approach to data analysis and visualization algorithm development that provides a pervasive parallelism without the complexity of parallel programming.
2. An adapter mechanism that encapsulates the change in behavior required to port the toolkit among devices and compilers.
3. A concept-enabled mechanism to automatically build parallel scheduling code from signatures using C++ templates.

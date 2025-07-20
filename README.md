# UEFI C Headers

This repository contains an implementation of C headers based on **UEFI Spec v2.11**. The implementation is incomplete, but aims to provide the minimum required functionality in order to bootstrap a kernel. The naming of structs/fields is **not** faithful to the original specifcaiton. I have renamed things to use a snake case naming convention, and also renamed things to more consistent and descriptive compared to the original specification. I haven't tested these headers extensively (especially on non-x86 architectures), so use them at your own discretion.

# CIS520-High-Performance-Scientific-Computing
This repository contains homework assignments, lab work, and solutions from the **High Performance Scientific Computing** course. 
It demonstrates a variety of computational techniques, including **Monte Carlo methods**, parallel computing with **OpenMP** and **MPI** (including **MPI Bcast**), **memory optimization**, and **algorithm design**. The work spans multiple languages and environments, with significant usage of **Jupyter Notebooks** for analysis, **C** for core computational algorithms, and **Shell scripting** for automation.


## Repository Structure

- **`Homework1/`**: Homework 1 - Monte Carlo Integration in 1D
  - Tasks:
    - Approximation of 1D integrals using Monte Carlo methods.
    - Error analysis using log-log plots.
    - Automation of experiments with Unix scripting.
  - Key Topics:
    - Numerical integration methods.
    - Runtime performance analysis.
  - Languages/Tools: C/C++, LATEX for report preparation, Unix scripting.

- **`Homework2/`**: Homework 2 - Estimation of π Using Monte Carlo
  - Tasks:
    - Calculation of π using 2D Monte Carlo integration.
    - Error trends and runtime analysis across varying sample sizes.
    - Comparison of runtimes between a personal laptop and Anvil supercomputer.
  - Key Topics:
    - Monte Carlo integration in higher dimensions.
    - Computational benchmarking.
  - Languages/Tools: C/C++, Unix job scripts.

- **`Homework3/`**: Homework 3 - Parallel Computing with MPI
  - Tasks:
    - Implementation of parallel algorithms using MPI.
    - Speedup and efficiency analysis with increasing processor counts.
  - Key Topics:
    - Message Passing Interface (MPI) basics.
    - Parallel scaling performance.
  - Languages/Tools: MPI with C/C++.

- **`Homework4/`**: Homework 4 - Performance Optimization
  - Tasks:
    - Profiling and optimizing existing numerical algorithms.
    - Exploration of cache-efficient strategies.
  - Key Topics:
    - Code profiling and optimization techniques.
    - Advanced memory management.
  - Languages/Tools: C/C++, gprof, and other profiling tools.

- **`Lab Work/`**: Lab Work
  - Contains scripts, exercises, and exploratory projects from lab sessions.
 
## Highlights

- Implements advanced computational techniques such as Monte Carlo integration, parallel computing with MPI, and memory optimization for scientific problems.
- Showcases efficient use of hardware resources, comparing single-core and multi-core performance on platforms like Anvil HPC.
- Automates large-scale numerical experiments using Unix scripts, ensuring reproducibility and scalability of computational workflows.
- Profiles and optimizes numerical algorithms for cache-efficient execution and reduced runtime overhead.
- Benchmarks algorithmic accuracy and performance with rigorous error analysis using log-log plots and statistical validation.
- Explores practical applications of numerical integration, including higher-dimensional problems and probabilistic modeling, with a focus on precision and computational cost trade-offs.

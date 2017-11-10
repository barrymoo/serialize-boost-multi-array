Notes
===

Trying to learn how to serialize a `boost::multi_array` for usage with `boost::mpi`

1. First test is a simple vector example `simple_vector` (done)
2. A simple matrix example: `simple_matrix` (done)
3. Write a generic matrix example: `generic_matrix` (done)
    - This code isn't that nice of an abstraction. I think I can fix it by adding a `serialize` for a `boost::multi_array`

#### Building and Running

Dependencies:

- Boost::MPI (compiled library, `pacman -S boost-libs` on Arch)

For `simple_vector` and `simple_matrix`:

```bash
cd <simple_{vector,matrix}>`
mkdir build
cd build
cmake -DCMAKE_CXX_COMPILER=<mpicxx> ..
make
```

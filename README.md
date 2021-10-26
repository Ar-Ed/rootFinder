# Root finder
- Performant root finder for user-defined functions with user-defined precision.
- There are 2 functions onw of which exposed in the header file.
- Exposed functions calls the other function to filter the range and return a root array (poor precision is better as long as roots are not missed)
- Precision is rectified and a pointer to the array of roots is returned by the user callable function.
- number_of_roots can be accessed by the user.

# STL Functions Used in CPP08 Exercise 01 - Span Class

This README documents all the Standard Template Library (STL) functions and components used in the implementation of the Span class.

## STL Containers

### `std::vector<int>`
- **Purpose**: Dynamic array container to store integers
- **Usage**: Main storage for the Span class (`std::vector<int> _v`)
- **Key Methods Used**:
  - `reserve(n)`: Pre-allocates memory for n elements without constructing them
  - `size()`: Returns the number of elements currently stored
  - `empty()`: Checks if the vector contains no elements
  - `push_back(value)`: Adds an element to the end of the vector
  - `begin()`: Returns iterator to the first element
  - `end()`: Returns iterator to one past the last element
  - `insert(position, first, last)`: Inserts elements from range [first, last) at position
  - `back()`: Returns reference to the last element
  - `front()`: Returns reference to the first element

## STL Algorithms

### `std::sort(first, last)`
- **Header**: `<algorithm>`
- **Purpose**: Sorts elements in ascending order
- **Usage**: Used in both `shortestSpan()` and `longestSpan()` to sort the vector copy
- **Parameters**: Takes two iterators defining the range to sort

### `std::adjacent_difference(first, last, result)`
- **Header**: `<numeric>`
- **Purpose**: Calculates differences between consecutive elements
- **Usage**: Used in `shortestSpan()` to find differences between consecutive sorted elements
- **Note**: The first element of the result is the original first element, not a difference

### `std::min(a, b)`
- **Header**: `<algorithm>`
- **Purpose**: Returns the smaller of two values
- **Usage**: Used in `shortestSpan()` to find the minimum difference

### `std::distance(first, last)`
- **Header**: `<iterator>` (implicitly included)
- **Purpose**: Calculates the number of elements between two iterators
- **Usage**: Used in the `addRange()` template function to check capacity before insertion

## STL Exception Classes

### `std::exception`
- **Header**: `<exception>`
- **Purpose**: Base class for standard exceptions
- **Usage**: Base class for the custom `spanException` class
- **Key Method**: `what()` - returns exception description

### `std::out_of_range`
- **Header**: `<stdexcept>`
- **Purpose**: Exception thrown when accessing elements outside valid range
- **Usage**: Thrown in `addNumber()` when trying to add to a full vector

## STL Utilities and Constants

### `std::string`
- **Purpose**: String class for storing error messages
- **Usage**: Used in the `spanException` class to store custom error messages
- **Key Method**: `c_str()` - returns C-style string representation

### `INT_MAX`
- **Header**: `<climits>` or `<limits>`
- **Purpose**: Maximum value for int type
- **Usage**: Used as initial value when finding minimum span in `shortestSpan()`

## Template Features Used

### Iterator-based Template Function
```cpp
template<typename T>
void addRange(T first, T last)
```
- **Purpose**: Allows adding elements from any container that provides iterators
- **STL Integration**: Works with any STL container's iterators (vector, list, array, etc.)

## Key STL Concepts Demonstrated

1. **RAII (Resource Acquisition Is Initialization)**: Vector automatically manages memory
2. **Iterator Pattern**: Used throughout for generic container access
3. **Exception Safety**: Proper exception handling with custom exceptions
4. **Template Programming**: Generic `addRange()` function works with any iterator type
5. **Algorithm Library**: Efficient sorting and difference calculations
6. **Container Operations**: Reserve, insert, and capacity management

## Performance Considerations

- `reserve()`: Pre-allocates memory to avoid multiple reallocations
- `sort()`: Typically O(n log n) complexity
- `adjacent_difference()`: Linear O(n) complexity
- `min()`: Constant O(1) complexity

This implementation demonstrates effective use of STL containers, algorithms, and exception handling patterns commonly used in modern C++ programming.
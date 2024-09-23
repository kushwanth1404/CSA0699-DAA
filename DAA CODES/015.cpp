import numpy as np

def split_matrix(matrix):
    """Splits a given matrix into four submatrices (quarters)."""
    row, col = matrix.shape
    row2, col2 = row // 2, col // 2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]

def strassen_multiply(A, B):
    """Performs Strassen's multiplication on matrices A and B."""
    # Base case: 1x1 matrix
    if len(A) == 1:
        return A * B

    # Split matrices into quarters
    A11, A12, A21, A22 = split_matrix(A)
    B11, B12, B21, B22 = split_matrix(B)

    # Recursively calculate the 7 Strassen products
    M1 = strassen_multiply(A11 + A22, B11 + B22)
    M2 = strassen_multiply(A21 + A22, B11)
    M3 = strassen_multiply(A11, B12 - B22)
    M4 = strassen_multiply(A22, B21 - B11)
    M5 = strassen_multiply(A11 + A12, B22)
    M6 = strassen_multiply(A21 - A11, B11 + B12)
    M7 = strassen_multiply(A12 - A22, B21 + B22)

    # Combine the results into final quadrants of the matrix
    C11 = M1 + M4 - M5 + M7
    C12 = M3 + M5
    C21 = M2 + M4
    C22 = M1 - M2 + M3 + M6

    # Reconstruct the result from the quadrants
    top = np.hstack((C11, C12))
    bottom = np.hstack((C21, C22))
    return np.vstack((top, bottom))

def next_power_of_two(n):
    """Returns the next power of two greater than or equal to n."""
    return 1 if n == 0 else 2**(n - 1).bit_length()

def pad_matrix(matrix, size):
    """Pads the matrix to the given size with zeros."""
    padded_matrix = np.zeros((size, size))
    padded_matrix[:matrix.shape[0], :matrix.shape[1]] = matrix
    return padded_matrix

def strassen(A, B):
    """Handles matrices of arbitrary size by padding them to the next power of two."""
    assert A.shape == B.shape, "Matrices must be of the same size"
    
    # Size of the matrices
    n = A.shape[0]
    m = next_power_of_two(n)
    
    # Pad matrices if they are not already a power of two size
    if m != n:
        A_padded = pad_matrix(A, m)
        B_padded = pad_matrix(B, m)
    else:
        A_padded = A
        B_padded = B

    # Perform Strassen multiplication on the padded matrices
    C_padded = strassen_multiply(A_padded, B_padded)
    
    # Remove padding and return the result of the original size
    return C_padded[:n, :n]

# Example usage:
A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
B = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])

C = strassen(A, B)
print(C)

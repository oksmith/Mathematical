Attribute VB_Name = "Module2"
Function Cholesky(matrix As Range)
 
Dim L() As Double, S As Double
Dim j As Long, k As Long, i As Long, n As Long, m As Long

n = matrix.Rows.Count
m = matrix.Columns.Count

'check that the matrix is square
If n <> m Then
    Cholesky = "Not a square matrix"
    Exit Function
End If

'set dimensions of the matrix, default value 0 everywhere
ReDim L(1 To n, 1 To n)
 
For j = 1 To n
    S = 0
    For k = 1 To j - 1
        S = S + L(j, k) ^ 2
    Next k
    
    L(j, j) = matrix(j, j) - S
    
    'we want to take a square root, but need to check that it's positive
    If L(j, j) <= 0 Then Exit For
    
    L(j, j) = Sqr(L(j, j))
    'we now have set the diagonal elements
    
    For i = j + 1 To n
        S = 0
        For k = 1 To j - 1
            S = S + L(i, k) * L(j, k)
        Next k
        L(i, j) = (matrix(i, j) - S) / L(j, j)
        'this is the non-diagonal element (i,j) in the bottom triangle
    Next i
Next j
 
Cholesky = L
 
End Function


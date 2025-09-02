class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        
        # Handle negative numbers by remembering the sign
        sign = -1 if x < 0 else 1
        x_abs = abs(x)
        
        # Reverse digits by string manipulation
        rev = int(str(x_abs)[::-1])
        
        # Restore sign
        rev *= sign
        
        # Check for 32-bit overflow
        if rev < INT_MIN or rev > INT_MAX:
            return 0
        return rev
        
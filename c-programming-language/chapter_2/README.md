# Chapter 2: Types, Operators, and Expressions

## Exercise 2-3: Hexadecimal to Integer Converter

### Problem
Convert a hexadecimal string (with optional `0x` prefix) to its integer equivalent.

### Current Solution

**Approach:** Right-to-left processing with explicit power calculation.

**Example:** `"1A3f"` = `15×16⁰ + 3×16¹ + 10×16² + 1×16³ = 6719`

**Complexity:** O(n²) due to nested loop for power calculation.

### Test Cases
- `"0x1A3f"` → 6719
- `"FF"` → 255  
- `"0Xabc"` → 2748

### Known Issues
1. Doesn't skip `0x` prefix (works by coincidence: both convert to 0)
2. Returns `0` for invalid chars (indistinguishable from valid `'0'`)

### Future Optimizations

**O(n) approach** - Left-to-right with Horner's method:
```c
result = 0;
for (i = 0; s[i] != '\0'; i++)
    result = result * 16 + convert(s[i]);
```

**Handle prefix explicitly:**
```c
if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    start = 2;  // Skip "0x"
```

**Better error handling:**
```c
return -1;  // Instead of 0 for invalid chars
```

---

**Note:** This is my initial working solution. Prioritizes clarity over optimization - improvements planned after progressing further in K&R.
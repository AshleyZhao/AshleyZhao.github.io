created: "2022-06-23 12:41:28 -0400"
title: "DataStage Functions used in pipelines expression builder"
---
{{site.data.keyword.attributedefs}}

# {{ site.data.keyword.datastage }} Functions used in pipelines Expression Builder

Use these {{ site.data.keyword.datastage }} functions in {{ site.data.keyword.pipeline_short }} code editors, for example, to define a user variable or build an advanced condition.
{: .shortdesc}

{% if site.prodkey=="cloud" %}
**Note:** This tool is provided as a beta release and is not supported for use in production environments.
{% endif %}

## Syntax for Expression Builder functions

In the syntax for arguments, square brackets indicate that an argument is optional.

A parameter might accept data of any type. This indicates you can input an argument of type string, int, float, null, and so on. For example the function `IsNull(input (any))` accepts the following parameter types, but is not exclusive to the following types:

```
ds.IsNull(1)
ds.IsNull("try null")
ds.IsNull(1.78)
ds.IsNull(null)
```
{: .codeblock}

{% if site.prodkey=="icpd" %}
**Note:** In the current version of {{site.data.keyword.pipeline}}, all input types of date, time, and timestamp are treated as strings.
{% endif %}

The Expression Builder uses these catagories for coding functions:

- [Conversion functions](#conversion)
- [Date and time functions](#datetime)
- [Logical functions](#logical)
- [Mathematical functions](#mathematical)
- [Number functions](#number)
- [Raw functions](#raw)
- [String functions](#string)
- [Utility functions](#utility)
- [Null functions](#null)
- [Macros functions](#macros_1)

## Conversion functions
{: #conversion}

Converts a single data element format to another.
<br>

### Ascii

Converts the values of characters in a string from EBCDIC to ASCII format.

<h4>Syntax</h4>

```
ds.Ascii(input (string))
```
{: .codeblock}

returns: the EDBCDI string converted to a resulting ASCII string of format string.

<h4>Example</h4>

The following code will return "65 66 67":

```
ds.Ascii("193 194 195")
```
{: .codeblock}
<br>

### Char

Returns an ASCII character from its numeric code value.

<h4>Syntax</h4>

```
ds.Char(code (uint8))
```
{: .codeblock}

returns: the corresponding character of format char.

<h4>Example</h4>

The following example outputs the ASCII code 65 as the character A.

```
ds.Char(65)
```
{: .codeblock}
<br>

### Checksum

Returns a cyclic redundancy code value for a string.

<h4>Syntax</h4>

```
ds.Checksum(input (string))
```
{: .codeblock}

returns: the checksum value of format string that is cyclic redundancy code.

<h4>Example</h4>

The following code will return 57158:

```
ds.Checksum("This is any arbitrary string value")
```
{: .codeblock}
<br>

### CRC32

Uses the CRC32 function to return a 16-bit cyclical redundancy code.

<h4>Syntax</h4>

```
ds.CRC32(input (string))
```
{: .codeblock}

returns: the result of format decimal.

<h4>Example</h4>

The following code will return 57158:

```
ds.CRC32("This is any arbitrary string value")
```
{: .codeblock}
<br>

### DateToString

Returns the string representation of the given date. The default format string for dates is "%yyyy%mm%dd", so, for example, the date 2009-08-25 is stored as the decimal number 20090825. However, you can optionally specify a format string that sets how the date is stored in the decimal number. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%yyyy-%mm-%dd", because the hyphen character (-) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%yyyy (four-digit year)

%yy (two-digit year)

%NNNNyy (two-digit year with cutoff)

%mm (two-digit month)

%dd (two-digit day of month)

%ddd (three-digit day of year)

```
{: .codeblock}

The literal digits 0 to 9 are also valid.

<h4>Syntax</h4>

```
ds.DateToString(date (date), [format (string)])
```
{: .codeblock}

returns: the date in string format.

<h4>Example</h4>

If `mylink.mydate` contains the date 18th August, 2009, then the following code returns the string "2009-08-18":

```
ds.DateToString(mylink.mydate)
```
{: .codeblock}

The following example outputs the date contained in the column `mylink.mydate` to a string with the format `dd:mm:yyyy`. If `mylink.mydate` contained the date 18th August, 2009, then the following code returns the string "18:08:2009":

```
ds.DateToString(mylink.mydate, "%dd:%mm:%yyyy")
```
{: .codeblock}
<br>

### DateToDecimal

Returns the given date as a packed decimal value. The default format string for dates is "%yyyy%mm%dd", so, for example, the date 2009-08-25 is stored as the decimal number 20090825. However, you can optionally specify a format string that sets how the date is stored in the decimal number. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%yyyy-%mm-%dd", because the hyphen character (-) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%yyyy (four-digit year)

%yy (two-digit year)

%NNNNyy (two-digit year with cutoff)

%mm (two-digit month)

%dd (two-digit day of month)

%ddd (three-digit day of year)

```
{: .codeblock}
The literal digits 0 to 9 are also valid.

<h4>Syntax</h4>

```
ds.DateToDecimal(basedate (date), [format (string)])
```
{: .codeblock}

returns: the date in decimal number format.

<h4>Example</h4>

If `mylink.basedate` contains the date 2012-08-18, then the following function stores the date as the decimal number 18082012:

```
ds.DateToDecimal(mylink.basedate, "%dd%mm%yyyy")
```
{: .codeblock}

If `mylink.basedate` contains the date 2012-08-18, then the following function stores the date as the decimal number 20120818:

```
ds.DateToDecimal(mylink.basedate)
```
{: .codeblock}
<br>

### DecimalToDate

Returns the given packed decimal as a date. Both the sign and the scale of the decimal number are ignored when it is converted to a date. The default format string is "%yyyy%mm%dd", so, for example, the date 2009-08-25 is stored as the decimal number 20090825. However, you can optionally specify a format string that sets how the date is stored in the decimal number. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%yyyy-%mm-%dd", because the hyphen character (-) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%yyyy (four-digit year)

%yy (two-digit year)

%NNNNyy (two-digit year with cutoff)

%mm (two-digit month)

%dd (two-digit day of month)

%ddd (three-digit day of year)

```
{: .codeblock}
The literal digits 0 to 9 are also valid.

<h4>Syntax</h4>

```
ds.DecimalToDate(basedec (decimal), [format (string)])
```
{: .codeblock}

returns: the decimal number in date format.

<h4>Example</h4>

If `mylink.mydecdata` contains the value 18082012, then the following function returns the date 2012-08-18:

```
ds.DecimalToDate(mylink.basedate, "%dd%mm%yyyy")
```
{: .codeblock}

If `mylink.mydecdata` contains the value -201208.18, then the following function returns the date 2012-08-18:

```
ds.DecimalToDate(mylink.basedate)
```
{: .codeblock}
<br>

### DecimalToDecimal

Returns the given decimal in decimal representation. The argument `rtype` optionally specifies a rounding type, and is set to one of the following values:

`ceil`: Rounds the source field toward positive infinity. For example, 1.4 -> 2, -1.6 -> -1.

`floor`: Rounds the source field toward negative infinity. For example, 1.6 -> 1, -1.4 -> -2.

`round_inf`: Rounds or truncate the source field toward the nearest representable value, breaking ties by rounding positive values toward positive infinity and negative values toward negative infinity. For example, 1.4 -> 1, 1.5 -> 2, -1.4 -> -1, -1.5 -> -2.

`trunc_zero`: Discard any fractional digits to the right of the rightmost fractional digit supported in the destination, regardless of sign. For example, if the destination is an integer, all fractional digits are truncated. If the destination is another decimal with a smaller scale, rounds or truncates to the scale size of the destination decimal. For example, 1.6 -> 1, -1.6 -> -1.

<h4>Syntax</h4>

```
ds.DecimalToDecimal(decimal (decimal), [rtype (string)])
```
{: .codeblock}

returns: the resulting decimal number.

<h4>Example</h4>

If `mylink.mydec` contains the decimal number 2.5345 the following function returns:

- the decimal number 2.54:

ds.DecimalToDecimal(mylink.mydec,"ceil")

- the decimal number 2.53.

ds.DecimalToDecimal(mylink.mydec,"floor")

- the decimal number 2.53.

ds.DecimalToDecimal(mylink.mydec,"trunc_zero")

- the decimal number 2.53.

ds.DecimalToDecimal(mylink.mydec,"round_inf")
<br>

### DecimalToDFloat

Returns the given decimal in `dfloat` representation. The optional argument `fix_zero` specifies that all zero decimal values are regarded as valid (by default, decimal numbers comprising all zeros are treated as invalid).

<h4>Syntax</h4>

```
ds.DecimalToDFloat(decimal (decimal), ["fix_zero"])
```
{: .codeblock}

returns: the decimal number in `dfloat` format.

<h4>Examples</h4>

If `mylink.mydec` contains the decimal number 00000004.00 the following function returns the `dfloat` number 4.

```
ds.DecimalToDFloat(mylink.mydec,"fix_zero")
```
{: .codeblock}

If `mylink.mydec` contains the decimal number 00012344.00 the following function returns the `dfloat` number 12344.

```
ds.DecimalToDFloat(mylink.mydec,"fix_zero")
```
{: .codeblock}

If `mylink.mydec` contains the decimal number 00012344.120 the following function returns the `dfloat` number 12344.12.

```
ds.DecimalToDFloat(mylink.mydec,"fix_zero")
```
{: .codeblock}

If `mylink.mydec` contains the decimal number 00012344.120 the following function returns the dfloat number 12344.12.

```
ds.DecimalToDFloat(mylink.mydec)
```
{: .codeblock}

If `mylink.mydec` contains the decimal number 00012344.000 the following function returns the dfloat number 12344.

```
ds.DecimalToDFloat(mylink.mydec)
```
{: .codeblock}
<br>

### DecimalToString

Returns the given decimal as a string. The argument `fix_zero` optionally specifies that all zero decimal values are regarded as valid (by default, decimal numbers comprising of all zeros are treated as invalid). This covers the case where the sign bits of the packed decimal representation are all 0 as well as all the content digits. This cast is not considered valid unless `fix_zero` is true.

<h4>Syntax</h4>

```
ds.DecimalToString(decimal (decimal), ["fix_zero"])
```
{: .codeblock}

returns: the decimal number in string format.

<h4>Examples</h4>

If `mylink.mydec` contains the decimal number 00000004.00, the following function returns:

- the string "4":

ds.DecimalToString(mylink.mydec,"suppress_zero")

- the string "0000000000000000000000000004.0000000000":

ds.DecimalToString(mylink.mydec,"fix_zero")

- the string "4":

ds.DecimalToString(mylink.mydec)
<br>

### DecimalToTime

Returns the given packed decimal as a time. You can optionally specify a format string that specifies how the time is stored in the decimal number. The default format string is "%hh%nn%ss", so, for example, the time 14:03:22 is stored as the decimal number 140322. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%hh:%nn:%ss", because the colon character (:) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%hh (two-digit hours using 24-hour clock)

%nn (two-digit minutes)

%ss (two-digit seconds)

%ss.N (two-digit seconds, plus the number of fractional digits allowed. The number of fractional digits is from one to six inclusive).
```
{: .codeblock}

The literal digits 0 to 9 are also valid.

If your specified format includes microseconds (for example, %ss.4), then the position of the decimal point is inferred in the decimal value. The position of the decimal point does not have to coincide with the specified scale of the decimal (for example, scale = 4).

<h4>Syntax</h4>

```
ds.DecimalToTime(decimal (decimal), [format (string)])
```
{: .codeblock}

returns: The decimal in time format.

<h4>Example</h4>

If `mylink.mytimedec` contains the decimal value 200658, then the following function returns the time 20:06:58:

```
ds.DecimalToTime(mylink.mytimedec)
```
{: .codeblock}

If the column mylink.mytimedec contains the decimal value 580620, then the following function returns the time 20:06:58:

```
ds.DecimalToTime(mylink.mytimedec, "%ss%nn%hh")
```
{: .codeblock}
<br>

### DecimalToTimestamp

Returns the given packed decimal as a timestamp. You can optionally specify a format string that specifies how the timestamp is stored in the decimal number. The default format string is "%hh%nn%ss", so, for example, the timestamp 2009-08-25 14:03:22 is stored as the decimal number 20090825140322. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%yyyy/%mm/%dd%hh:%nn:%ss", because the slash character (/) and the colon character (:) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%yyyy (four-digit year)

%yy (two-digit year)

%NNNNyy (two-digit year with cutoff)

%mm (two-digit month)

%dd (two-digit day of month)

%ddd (three-digit day of year)

%hh (two-digit hours using 24-hour clock)

%nn (two-digit minutes)

%ss (two-digit seconds)

%ss.N (two-digit seconds, plus the number of fractional digits allowed. The number of fractional digits is from one to six inclusive).
```
{: .codeblock}

The literal digits 0 to 9 are also valid.

If your specified format includes microseconds (for example, %ss.4), then the position of the decimal point is inferred in the decimal value. The position of the decimal point does not have to coincide with the specified scale of the decimal (for example, scale = 4).

<h4>Syntax</h4>

```
ds.DecimalToTimestamp(decimal (decimal), [format (string)])
```
{: .codeblock}

returns: The decimal in timestamp format.

<h4>Example</h4>

If `mylink.mytimestampdec` contains the value 19580818200658, then the following function returns the timestamp 1958-08-18 20:06:58:

```
ds.DecimalToTimestamp(mylink.mytimestampdec)
```
{: .codeblock}

If `link.mytimestampdec` contains the decimal value 200658220818, then the following function returns the timestamp 2022-08-18 20:06:58:

```
ds.DecimalToTimestamp(mylink.mytimestampdec, "%hh%nn%ss%yy%mm%dd")
```
{: .codeblock}
<br>

### DFloatToDecimal

Returns the given dfloat in decimal representation. The argument `rtype` optionally specifies a rounding type, and is set to one of the following values:

`ceil`: Rounds the source field toward positive infinity. For example, 1.4 -> 2, -1.6 -> -1.

`floor`: Rounds the source field toward negative infinity. For example, 1.6 -> 1, -1.4 -> -2.

`round_inf`: Rounds or truncate the source field toward the nearest representable value, breaking ties by rounding positive values toward positive infinity and negative values toward negative infinity. For example, 1.4 -> 1, 1.5 -> 2, -1.4 -> -1, -1.5 -> -2.

`trunc_zero`: Discard any fractional digits to the right of the rightmost fractional digit supported in the destination, regardless of sign. For example, if the destination is an integer, all fractional digits are truncated. If the destination is another decimal with a smaller scale, rounds or truncates to the scale size of the destination decimal. For example, 1.6 -> 1, -1.6 -> -1.

<h4>Syntax</h4>

```
ds.DFloatToDecimal(number (dfloat), [rtype (string)])
```
{: .codeblock}

returns: the decimal in dfloat format.

<h4>Examples</h4>

If `mylink.myfloat` contains the dfloat number 2.534, the following function returns:

- the decimal number 2.54:

ds.DFloatToDecimal(mylink.mydec,"ceil")

- the decimal number 2.53:

ds.DFloatToDecimal(mylink.mydec,"floor")

- the decimal number 2.53:

ds.DFloatToDecimal(mylink.mydec,"trunc_zero")

- the decimal number 2.53:

ds.DFloatToDecimal(mylink.mydec,"round_inf")
<br>

### DfloatToStringNoExp

Returns the given dfloat in its string representation with no exponent, using the specified scale.

<h4>Syntax</h4>

```
ds.DfloatToStringNoExp(number (dfloat), scale (string))
```
{: .codeblock}

returns: the dfloat number in string format.

<h4>Examples</h4>

If `mylink.myfloat` contains the dfloat number 2.534, then the following function returns the string "2.5":

```
ds.DfloatToStringNoExp(mylink.myfloat, "2")
```
{: .codeblock}
<br>

### Dtx

Converts a decimal integer to hexadecimal.

<h4>Syntax</h4>

```
ds.Dtx(number (int32), size(int8))
```
{: .codeblock}

returns: the result of format string.

<h4>Example</h4>

The following code will return "002F":

```
ds.Dtx(47,4)
```
{: .codeblock}
<br>

### Ebcdic

Converts each character of expression from its ASCII representation value to its EBCDIC representation value.

<h4>Syntax</h4>

```
ds.Ebcdic(input (string))
```
{: .codeblock}

returns: the ASCII string converted to a resulting EDBCDII string.

<h4>Example</h4>

The following code will return "193 194 195 64 241 242 243":

```
ds.Ebcdic("ABC 123")
```
{: .codeblock}
<br>

### Iconv

Converts a string to an internal storage format.

<h4>Syntax</h4>

```
ds.Iconv(string (string), code (string))
```
{: .codeblock}

returns: the internal storage format in string format.

<h4>Example</h4>

The following code will return 10740:

```
ds.Iconv("27 MAY 97", "D2")
```
{: .codeblock}

The following code will return 10740:

```
ds.Iconv("1997 5 27", "D YMD")
```
{: .codeblock}

<br>

### IntToBool

Convert integer to bool type. Returns true for any non-zero value, and false for 0.

<h4>Syntax</h4>

```
ds.IntToBool(integer (int))
```
{: .codeblock}

returns: the boolean value of true or false.

<h4>Example</h4>

The value of 2 will return true.

```
ds.IntToBool(2)
```
{: .codeblock}

<br>

### IsValid

Returns whether the given string is valid for the given type.

Valid types are "date", "decimal", "dfloat", "sfloat", "int8", "uint8", "int16", "uint16", "int32", "uint32", "int64", "uint64", "string", "time", "timestamp".

For data types of date, time, and timestamp, you can optionally specify a format string. The format string describes the format that your input data uses when it differs from the default formats for date, time, or timestamp. The default format for date is "%yyyy-%mm-%dd". The default format for time is "%hh:%mm:%ss". The default format for timestamp is "%yyyy-%mm-%dd %hh:%mm:%ss". This function does not log warnings.

<h4>Syntax</h4>

```
ds.IsValid(type (string), teststring (string), [format (string)])
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Example</h4>

If `mylink.mystring` contains the string "1", then the following function returns the value 1:

```
ds.IsValid("int8", mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "380096.06", then the following function returns the value 0:

```
ds.IsValid("int8", mylink.mystring)
```
{: .codeblock}
<br>

### IsValidDate

Returns whether the given value is valid for the type date. This function logs warnings.

<h4>Syntax</h4>

```
ds.IsValidDate(testdate (date))
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

If `mylink.mydate` contains the date 2011-09-13, then the following function returns the value 1.

```
ds.IsValidDate(mylink.mydate)
```
{: .codeblock}

If `mylink.mydate` contains the string "380096.06", then the following function returns the value 0, because the converted string is not a valid date.

```
ds.IsValidDate(mylink.mydate)
```
{: .codeblock}
<br>

### IsValidDecimal

Returns whether the given value is valid for the type decimal. If the `allzerosflag` is set to 0, then an all-zeroes representation is not valid. The `allzerosflag` is set to 0 by default.

<h4>Syntax</h4>

```
ds.IsValidDecimal(testvalue (decimal), [allzerosflag (uint8)])
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Examples</h4>

If `mylink.mynum` contains the value 310007.65, then the following function returns the value 1.

```
ds.IsValidDecimal(mylink.mynum)
```
{: .codeblock}

### IsValidTime

Returns whether the given time is valid for the type time.

<h4>Syntax</h4>

```
ds.IsValidTime(testtime (time))
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Examples</h4>

If `mylink.mytime` contains the time 23:09:22, then the following function returns the value 1:

```
ds.IsValidTime(mylink.mytime)
```
{: .codeblock}

### IsValidTimestamp

Returns whether the given timestamp is valid for the type timestamp.

<h4>Syntax</h4>

```
ds.IsValidTimestamp(testtimestamp (timestamp))
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the time 2011-09-13 23:09:22, then the following function returns the value 1:

```
ds.IsValidTimestamp(mylink.mytimestamp)
```
{: .codeblock}

### Oconv

Converts an expression to an output format.

<h4>Syntax</h4>

```
ds.Oconv(expression (string), conversion (string))
```
{: .codeblock}

returns: the result to an output format of format string.

<h4>Example</h4>

The following code will return 1997-147:

```
ds.Oconv(10740, "D-YJ")
```
{: .codeblock}

The following code will return 27 MAY 97:

```
ds.Oconv(10740, "D DMY, [A3,2]")
```
{: .codeblock}

### RawNumAt

Returns the integer value at the specified index value in the specified raw field. The index starts at 0.

<h4>Syntax</h4>

```
ds.RawNumAt(rawfield (string), index (int32))
```
{: .codeblock}

returns: the integer value at the index in int32 format.

<h4>Examples</h4>

If the `column mylink.myraw` contains a raw value derived from the string "hello" (which is "{ 0x68 0x65 0x6C 0x6C 0x6F }"), then the following function returns the integer 104 (the ASCII code for the character h):

```
ds.RawNumAt(mylink.myraw, 0)
```
{: .codeblock}

If `mylink.myraw` contains a raw value derived from the string "hello" (which is "{ 0x68 0x65 0x6C 0x6C 0x6F }"), then the following function returns 0 because the specified index is out of range:

```
ds.RawNumAt(mylink.myraw, 12)
```
{: .codeblock}
<br>

### RawToString

Returns the given raw value as a string representation. You must ensure that the raw input value contains a sequence of bytes that are valid as characters in the target character set in which the output string is used.

For example, the raw value `{ 0xE0 0x41 0x42 }` is not a valid sequence of UTF-8 characters, since the lead byte, 0xE0, is supposed to be followed by a byte in the range [0x80..0xBF].

If a raw value `{ xE0 x41 x42 }` is passed to the RawToString function, there could be an error if the output string is then accessed as if it were encoded in UTF-8.

<h4>Syntax</h4>

```
ds.RawToString(rawfield (string))
```
{: .codeblock}

returns: the given raw value as a string.

<h4>Examples</h4>

If `mylink.myraw` contains the value `{ 0x31 0x31 0x30 0x35 0x32 0x32 0x30 0x39 }`, then the following function returns the string "11052209".

```
ds.RawToString(mylink.myraw)
```
{: .codeblock}
<br>

### Seq

Generates a numeric code value from an ASCII character. You can optionally specify the `allow8bits` argument to convert 8-bit ASCII values.

<h4>Syntax</h4>

```
ds.Seq(seq (char))
```
{: .codeblock}

returns: the ASCII character numeric code.

<h4>Examples</h4>

The following example outputs the character A as the ASCII code 65.

```
ds.Seq("A")
```
{: .codeblock}
<br>

### SeqAt

Returns the numeric code point value of the character at the specified position in the given string. The index starts at 0. If the specified index is out of range, the function returns 0.

<h4>Syntax</h4>

```
ds.SeqAt(basestring (string), index (int32))
```
{: .codeblock}

returns: numeric code point value of the character at the specified position in the given string in `int32` format.

<h4>Examples</h4>

If `mylink.mystring` contains the string "horse", then the following function returns the value 0x6F (that is, the ASCII value of the character o).

```
ds.SeqAt(mylink.mystring, 1)
```
{: .codeblock}
<br>

### StringToBool

Converts string to bool type. Return false for empty string, return true for any other value.

<h4>Syntax</h4>

```
ds.StringToBool(string (string))
```
{: .codeblock}

returns: the boolean value of true or false.

<h4>Example</h4>

An empty string returns false.

```
ds.StringToBool("")
```
{: .codeblock}
<br>

### StringToDate

Returns a date from the given string in the specified format. You do not have to specify a format string if your string contains a date in the default format yyyy-mm-dd.

<h4>Syntax</h4>

```
ds.StringToDate(string (string), [format (string)])
```
{: .codeblock}

returns: the string to date in specified format.

<h4>Examples</h4>
</b>
If `mylink.mystring` contains the string "1958-08-18", then the following function returns the date 1958-08-18.

```
ds.StringToDate(mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "18:08:1958", then the following function returns the date 1958-08-18.

```
ds.StringToDate(mylink.mystring,"%dd:%mm:%yyyy")
```
{: .codeblock}
<br>

### StringToDecimal

Returns the given string as a decimal representation. The argument `rtype` optionally specifies a rounding type, and is set to one of the following values:

`ceil`: Rounds the source field toward positive infinity. For example, 1.4 -> 2, -1.6 -> -1.

`floor`: Rounds the source field toward negative infinity. For example, 1.6 -> 1, -1.4 -> -2.

`round_inf`: Rounds or truncate the source field toward the nearest representable value, breaking ties by rounding positive values toward positive infinity and negative values toward negative infinity. For example, 1.4 -> 1, 1.5 -> 2, -1.4 -> -1, -1.5 -> -2.

`trunc_zero`: Discard any fractional digits to the right of the rightmost fractional digit supported in the destination, regardless of sign. For example, if the destination is an integer, all fractional digits are truncated. If the destination is another decimal with a smaller scale, rounds or truncates to the scale size of the destination decimal. For example, 1.6 -> 1, -1.6 -> -1.

<h4>Syntax</h4>

```
ds.StringToDecimal(string (string), [rtype (string)])
```
{: .codeblock}

returns: the string in decimal format.

<h4>Examples</h4>

If `mylink.mystring` contains the string "19982.22", then the following function returns the decimal 19982.22.

```
ds.StringToDecimal(mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "19982.2276", then the following function returns the decimal 19982.23.

```
ds.StringToDecimal(mylink.mystring,"ceil")
```
{: .codeblock}
<br>

### StringToRaw

Returns a string as its raw code value.

<h4>Syntax</h4>

```
ds.StringToRaw(string (string))
```
{: .codeblock}

returns: the corresponding raw code value of the string.

<h4>Examples</h4>

If `mylink.mystring` contains the string "hello", then the following function returns the value "{0x68 0x65 0x6C 0x6C 0x6F}".

```
ds.StringToRaw(mylink.mystring)
```
{: .codeblock}
<br>

### StringToTime

Returns a time representation of the given string.

<h4>Syntax</h4>

```
ds.StringToTime(string (string), [format (string)])
```
{: .codeblock}

returns: the string in time value.

<h4>Examples</h4>

If `mylink.mystring` contains the string "20:06:58", then the function returns a time of 20:06:58.

```
ds.StringToTime(mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "20: 6:58", then the function returns a time of 20:06:58.

```
ds.StringToTime(mylink.mystring,"%(h,s):%(n,s):%(s,s)")
```
{: .codeblock}

### StringToTimestamp

Returns the given string in timestamp format.

<h4>Syntax</h4>

```
ds.StringToTimestamp(string (string), [format (string)])
```
{: .codeblock}

returns: the string in timestamp format.

<h4>Examples</h4>

If `mylink.mystring` contains the string "1958-08-08 20:06:58", then the function returns the timestamp 1958-08-08 20:06:58.

```
ds.StringToTimestamp(mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "8/ 8/1958 20: 6:58", then the function returns the timestamp 1958-08-08 20:06:58.

```
ds.StringToTimestamp(mylink.mystring, "%(d,s)/%(m,s)/%yyyy%(h,s):%(n,s):%(s,s)")
```
{: .codeblock}

### StringToUstring

Returns a `ustring` from the given string, optionally by using the specified map (otherwise, it uses project default).

<h4>Syntax</h4>

```
ds.StringToUstring(string (string), [mapname (string)])
```
{: .codeblock}

returns: the string in ustring format.

<h4>Examples</h4>

If `mylink.mystring` contains the string "11052009", then the following function returns the ustring "11052009".

```
ds.StringToUstring(mylink.mystring)
```
{: .codeblock}
<br>

### TimestampToDate

Returns a date from the given timestamp.

<h4>Syntax</h4>

```
ds.TimestampToDate(timestamp (timestamp))
```
{: .codeblock}

returns: the resulting date of the timestamp.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the following function returns the date 1958-08-18:

```
ds.TimestampToDate(mylink.mytimestamp)
```
{: .codeblock}
<br>

### TimestampToDecimal

Returns the given timestamp as a packed decimal. The default format string is " %yyyy%mm%dd%hh%nn%ss". For example, the timestamp 2009-08-25 14:03:22 is stored as the decimal number 20090825140322. However, you can optionally specify a format string that sets how the date is stored in the decimal number. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%yyyy/%mm/%dd%hh:%nn:%ss", because the slash character (/) and the colon character (:) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%yyyy (four-digit year)

%yy (two-digit year)

%NNNNyy (two-digit year with cutoff)

%mm (two-digit month)

%dd (two-digit day of month)

%ddd (three-digit day of year)

%hh (two-digit hours using 24-hour clock)

%nn (two-digit minutes)

%ss (two-digit seconds)

%ss.N (two-digit seconds, plus the number of fractional digits allowed. The number of fractional digits is from one to six inclusive).
```
{: .codeblock}

The literal digits 0 to 9 are also valid.

If your specified format includes microseconds (for example, %ss.4), then the position of the decimal point is inferred in the decimal value. The position of the decimal point does not have to coincide with the specified scale of the decimal (for example scale = 4).

<h4>Syntax</h4>

```
ds.TimestampToDecimal(timestamp (timestamp), [format (string)])
```
{: .codeblock}

returns: the resulting timestamp in decimal format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the following function returns the decimal value 19580818200658:

```
ds.TimestampToDecimal(mylink.mytimestamp)
```
{: .codeblock}

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the following function returns the decimal value 200658580818:

```
ds.TimestampToDecimal(mylink.mytimestamp, "%hh%nn%ss%yy%mm%dd")
```
{: .codeblock}
<br>

### TimestampToString

Returns the given timestamp as string format.

<h4>Syntax</h4>

```
ds.TimestampToString(timestamp (timestamp), [format (string)])
```
{: .codeblock}

returns: the resulting timestamp in string format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the function returns the string "1958-08-18 20:06:58".

```
ds.TimestampToString(mylink.mytimestamp)
```
{: .codeblock}

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the function returns the string "18/08/1958 20:06:58":

```
ds.TimestampToString(mylink.mytimestamp, "%dd/%mm/%yyyy %hh:%nn:%ss")
```
{: .codeblock}
<br>

### TimestampToTime

Returns the given timestamp as time format.

<h4>Syntax</h4>

```
ds.TimestampToTime(timestamp (timestamp), [format (string)])
```
{: .codeblock}

returns: the resulting timestamp in time format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the timestamp 1958-08-18 20:06:58, then the function returns the time 20:06:58:

```
ds.TimestampToTime(mylink.mytimestamp)
```
{: .codeblock}
<br>

### TimeToString

Returns a string from the given time.

<h4>Syntax</h4>

```
ds.TimeToString(timestamp (timestamp), [format (string)])
```
{: .codeblock}

returns: the result in time format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 20:06:58, then the following function returns the string "20:06:58":

```
ds.TimeToString(mylink.mytime)
```
{: .codeblock}

If `mylink.mytime` contains the time 20:06:58, then the following function returns the string "58:06:20":

```
ds.TimeToString(mylink.mytime, "%ss:%nn:%hh")
```
{: .codeblock}
<br>

### TimeToDecimal

Returns the given time as a packed decimal. The default format string is " %hh%nn%ss", so, for example, the time 14:03:22 is stored as the decimal number 140322. However, you can optionally specify a format string that specifies how the time is stored in the decimal number. Format strings can only specify a format that contains numbers. For example, you cannot specify a format string such as "%hh:%nn:%ss", because the colon character (:) cannot be stored in a packed decimal value. The following tokens are valid for conversions to or from decimal values:

```
%hh (two-digit hours using 24-hour clock)

%nn (two-digit minutes)

%ss (two-digit seconds)

%ss.N (two-digit seconds, plus the number of fractional digits allowed. The number of fractional digits is from one to six inclusive).
```
{: .codeblock}

The literal digits 0 to 9 are also valid.

If your specified format includes microseconds (for example, %ss.4), then the position of the decimal point is inferred in the decimal value. The position of the decimal point does not have to coincide with the specified scale of the decimal (for example scale = 4).

<h4>Syntax</h4>

```
ds.TimeToDecimal(time (time), [format (string)])
```
{: .codeblock}

returns: the time in decimal format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 20:06:58, then the following function returns the decimal value 200658:

```
ds.TimeToDecimal(mylink.mytime)
```
{: .codeblock}

If `mylink.mytime` contains the time 20:06:58, then the following function returns the decimal value 580620:

```
ds.TimeToDecimal(mylink.mytime, "%ss%nn%hh")
```
{: .codeblock}
<br>

### UniChar

Generates a single Unicode character based on a decimal value, in the range 0 to 65535.

<h4>Syntax</h4>

```
ds.UniChar(expression (int32))
```
{: .codeblock}

returns: the result of format string.

<h4>Example</h4>

The following code will return "õ":

```
ds.UniChar(0x00F5)
```
{: .codeblock}
<br>

### UniSeq

Generates a decimal value based on a single Unicode character.

<h4>Syntax</h4>

```
ds.UniSeq(expression (string))
```
{: .codeblock}

returns: the corresponding decimal to the Unicode character of format int32.

<h4>Example</h4>

The following code will return 195:

```
ds.UniSeq("ä")
```
{: .codeblock}
<br>

### UstringToString

Returns a string from the given ustring, optionally by using the specified map (otherwise uses the project default map).

<h4>Syntax</h4>

```
ds.UstringToString(string (ustring), [mapname(string)])
```
{: .codeblock}

returns: the result in string format.

<h4>Examples</h4>

If `mylink.myustring` contains the ustring "11052009", then the following function returns the string "11052009":

```
ds.UstringToString(mylink.myustring)
```
{: .codeblock}

### Xtd

Converts a hexadecimal string to decimal.

<h4>Syntax</h4>

```
ds.Xtd(hexadecimal (string))
```
{: .codeblock}

returns: the corresponding decimal value to the hexidecimal string.

<h4>Example</h4>

The following code will return 48879:

```
ds.Xtd("beef")
```
{: .codeblock}
<br>

### Int

Returns the integer portion of an expression. Any arithmetic operations specified are calculated by using the full accuracy of the system. The fractional portion of the value is truncated, not rounded, and the integer portion remaining is returned.

<h4>Syntax</h4>

```
ds.Int(expression (dfloat))
```
{: .codeblock}

returns: the decimal value rounded and converted to type int64.

<h4>Example</h4>

The following code will return 454:

```
ds.Int(454.95)
```
{: .codeblock}

The following code will return 2:

```
ds.Int(2.35)
```
{: .codeblock}
<!--End of conversion functions-->
<br>

## Date and time functions
{: #datetime}

Use these functions for data and time functions in an expression.

Functions that specify dates, times, or time stamps in the arguments use strings with specific formats:

- For a date, the format is `%yyyy-%mm-%dd`
- For a time, the format is `%hh:%nn:%ss`. If extended to include microseconds, the format is `%hh:%nn:%ss.x` where *x* gives the number of decimal places seconds is given to.
- For a time stamp, the format is the date format followed by the time format.

Functions that have the days of week in the argument take a string that specifies the day of the week. The day is specified as a three-letter abbreviation, or the full name. For example, the strings "thu" and "thursday" are both valid.
<br>

### CurrentDate

Returns the date that the job runs.

<h4>Syntax</h4>

```
ds.CurrentDate()
```
{: .codeblock}

returns: the current date in date format.

<h4>Examples</h4>

Use this function to get the current date.

```
ds.CurrentDate()
```
{: .codeblock}
<br>

### CurrentTime

Returns the time at which the job runs.

<h4>Syntax</h4>

```
ds.CurrentTime()
```
{: .codeblock}

returns: the current time in time format.

<h4>Examples</h4>

Use this function to get the current time.

```
ds.CurrentTime()
```
{: .codeblock}
<br>

### CurrentTimeMS

Returns the time, including microseconds, at which the job runs.

<h4>Syntax</h4>

```
ds.CurrentTimeMS()
```
{: .codeblock}

returns: the current time in time format, including microseconds.

<h4>Examples</h4>

Use this function to retrieve the current time to the output data.

```
ds.CurrentTimeMS()
```
{: .codeblock}
<br>

### CurrentTimestamp

Returns a time stamp that gives the date and time that the job runs.

<h4>Syntax</h4>

```
ds.CurrentTimestamp()
```
{: .codeblock}

returns: the current timestamp in timestamp format.

<h4>Examples</h4>

Use this function to retrieve the current timestamp to the output data.

```
ds.CurrentTimestamp()
```
{: .codeblock}
<br>

### CurrentTimestampMS

Returns a time stamp, including microseconds, that gives the date and time that the job runs.

<h4>Syntax</h4>

```
ds.CurrentTimestampMS()
```
{: .codeblock}

returns: the current timestamp in timestamp format.

<h4>Examples</h4>

Use this function to retrieve the current timestamp to the output data.

```
ds.CurrentTimestampMS()
```
{: .codeblock}
<br>

### Date

Returns a single numeric value of days elapsed between the internal system date and December 31, 1967, which is day 0. All dates after are positive numbers representing the number of days elapsed since day 0. All dates before are negative numbers representing the number of days before day 0.

<h4>Syntax</h4>

```
ds.Date()
```
{: .codeblock}

returns: the resulting date of format int.

<h4>Examples</h4>

If the current date is November 15, 1967, the following code returns -46. If the current date is February 15, 1968, the following code returns 46:

```
ds.Date()
```
{: .codeblock}
<br>

### DateFromDaysSince

Returns a date by adding an integer to a baseline date. The integer can be negative to return a date that is earlier than the baseline date.

<h4>Syntax</h4>

```
ds.DateFromDaysSince(number (int32), [baseline_date_object (string)])
```
{: .codeblock}

returns: a date by adding an integer to a baseline date that the user enters.

<h4>Examples</h4>

If `mylink.myintcol` contains the integer 18250, and `mylink.mydatecol` contains the date 1958-08-18, then the three following functions are equivalent, and return the date 2008-08-05:

```
ds.DateFromDaysSince(18250,"1958-08-18")
ds.DateFromDaysSince(mylink.myintcol,"1958-08-18")
ds.DateFromDaysSince(mylink.myintcol,mylink.mydatecol)
```
{: .codeblock}

If `mylink.mynegintcol` contains the integer -1, and `mylink.mydatecol` contains the date 1958-08-18, then the following three functions are equivalent, and return the date 1958-08-17:

```
ds.DateFromDaysSince(-1,"1958-08-18")
ds.DateFromDaysSince(mylink.mynegintcol,"1958-08-18")
ds.DateFromDaysSince(mylink.mynegintcol,mylink.mydatecol)
```
{: .codeblock}
<br>

### DateFromDaysSince2

Returns a date by adding an integer to a baseline date. The integer can be negative to return a date that is earlier than the baseline date.

<h4>Syntax</h4>

```
ds.DateFromDaysSince2(number (int32), [baseline_date_object (date)])
```
{: .codeblock}

returns: a date by adding an integer to a baseline date that the user enters.

<h4>Examples</h4>

If `mylink.myint` contains the integer 18250, and `mylink.mydate` contains the date 1958-08-18, then the three following functions are equivalent, and return the date 2008-08-05:

```
ds.DateFromDaysSince2(18250,"1958-08-18")
ds.DateFromDaysSince2(mylink.myint,"1958-08-18")
ds.DateFromDaysSince2(mylink.myint, mylink.mydate)
```
{: .codeblock}

If `mylink.mynegint` contains the integer -1, and `mylink.mydate` contains the date 1958-08-18, then the following three functions are equivalent, and return the date 1958-08-17:

```
ds.DateFromDaysSince2(-1,"1958-08-18")
ds.DateFromDaysSince2(mylink.mynegint,"1958-08-18")
ds.DateFromDaysSince2(mylink.mynegint, mylink.mydate)
```
{: .codeblock}
<br>

### DateFromComponents

Returns a date from the given years, months, and day of month that is given as three separate values.

<h4>Syntax</h4>

```
ds.DateFromComponents(years (int32), months (int32), dayofmonth (int32))
```
{: .codeblock}

returns: a single date with the specified values.

<h4>Examples</h4>

If `mylink.year` contains the value 2010, `mylink.month` contains the value 12, and `mylink.dayofmonth` contains the value 2, then the two following functions are equivalent, and return the date 2010-12-02.

```
ds.DateFromComponents(2010, 12, 2)
ds.DateFromComponents(mylink.year, mylink.month, mylink.dayofmonth)
```
{: .codeblock}
<br>

### DateFromJulianDay

Returns a date from the given Julian day number.

<h4>Syntax</h4>

```
ds.DateFromJulianDay(julianday (uint32))
```
{: .codeblock}

returns: the date of the Julian day value given.

<h4>Examples</h4>

If `mylink.myjul` contains the value 2454614, then the two following functions are equivalent, and return the date 2008-05-27.

```
ds.DateFromJulianDay(2454614)
ds.DateFromJulianDay(mylink.myjul)
```
{: .codeblock}
<br>

### DateOffsetByComponents

Returns the given date, with offsets applied from the given year offset, month offset, and day of month offset, given as three separate values. The offset values can each be positive, zero, or negative.

<h4>Syntax</h4>

```
ds.DateOffsetByComponents(basedate (date), year_offset (int32), month_offset (int32), dayofmonth_offset (int32))
```
{: .codeblock}

returns: The given date offset of format date.

<h4>Examples</h4>

If `mylink.basedate` contains 2011-08-18 and `mylink.yearos` contains the value 2, `mylink.monthos` contains the value 0, and `mylink.dayofmonthosol` contains the value 0, then the two following functions are equivalent, and return the date 2013-08-18.

```
ds.DateOffsetByComponents("2011-08-18", 2, 0, 0)
ds.DateOffsetByComponents(mylink.basedate, mylink.yearos, mylink.monthos, mylink.dayofmonthos)
```
{: .codeblock}

If `mylink.basedate` contains 2011-08-18 and `mylink.yearos` contains the value -2, `mylink.monthos` contains the value 0, and `mylink.dayofmonthosol` contains the value 0, then the two following functions are equivalent, and return the date 2009-08-18.

```
ds.DateOffsetByComponents("2011-08-18", -2, 0, 0)
ds.DateOffsetByComponents(mylink.basedate, mylink.yearos, mylink.monthos, mylink.dayofmonthos)
```
{: .codeblock}

<br>

### Day

Returns day of month from the system date.

<h4>Syntax</h4>

```
ds.Day()
```
{: .codeblock}

returns: day of the month in int format.

<h4>Examples</h4>

If the current date is 1967-12-31, the following code returns 31.

```
ds.Day()
```
{: .codeblock}
<br>

### DaysSinceFromDate

Takes a given date of type date and a source date of type string, and returns the number of days from the source date to the given date.

<h4>Syntax</h4>

```
ds.DaysSinceFromDate(given_date (date), source_date_string (string))
```
{: .codeblock}

returns: the difference in days between the two given dates of type int32.

<h4>Examples</h4>

If `mylink.mysourcedate` contains the date 1958-08-18 and `mylink.mygivendate` contains the date 2008-08-18, then the two following functions are equivalent, and return the integer value 18263.

```
ds.DaysSinceFromDate(mylink.mygivendate, mylink.mysourcedate)
ds.DaysSinceFromDate("2008-08-18","1958-08-18")
```
{: .codeblock}
<br>

### DaysSinceFromDate2

Takes a given date of type date and a source date of type date, and returns the number of days from the source date to the given date.

<h4>Syntax</h4>

```
ds.DaysSinceFromDate2(given_date (date), source_date_object (date))
```
{: .codeblock}

returns: the difference in days between the two given dates in int32 format.

<h4>Examples</h4>

If `mylink.mysourcedate` contains the date 1958-08-18 and `mylink.mygivendate` contains the date 2008-08-18, then the two following functions are equivalent, and return the integer value 18263.

```
ds.DaysSinceFromDate2(mylink.mygivendate, mylink.mysourcedate)
ds.DaysSinceFromDate2("2008-08-18","1958-08-18")
```
{: .codeblock}
<br>

### DaysInMonth

Returns the number of days in the month in the given base date.

<h4>Syntax</h4>

```
ds.DaysInMonth(basedate (date))
```
{: .codeblock}

returns: the number of days in the month in int32 format.

<h4>Examples</h4>

If `mylink.mysourcedate` contains the date 1958-08-18, then the two following functions are equivalent, and return the integer value 31.

```
ds.DaysInMonth(mylink.mysourcedate)
ds.DaysInMonth("1958-08-18")
```
{: .codeblock}
<br>

### DaysInYear

Returns the number of days in the year in the given base date.

<h4>Syntax</h4>

```
ds.DaysInYear(basedate (date))
```
{: .codeblock}

returns: the number of days in the year in int32 format.

<h4>Examples</h4>

If mylink.mysourcedate contains the date 2012-08-18, then the two following functions are equivalent, and return the integer value 366.

```
ds.DaysInYear(mylink.mysourcedate)
ds.DaysInYear("2012-08-18")
```
{: .codeblock}

If mylink.mysourcedate contains the date 2011-08-18, then the two following functions are equivalent, and return the integer value 365.

```
ds.DaysInYear(mylink.mysourcedate)
ds.DaysInYear("2011-08-18")
```
{: .codeblock}
<br>

### DateOffsetByDays

Returns the given date offset by the given number of days. The offset value can be positive, zero, or negative.

<h4>Syntax</h4>

```
ds.DateOffsetByDays(basedate (date), dayoffset (int32))
```
{: .codeblock}

returns: the date object with the corresponding offset.

<h4>Examples</h4>

If `mylink.basedate` contains 2011-08-18 and `mylink.dayoffset` contains the value 2, then the two following functions are equivalent, and return the date 2011-08-20.

```
ds.DateOffsetByDays("2011-08-18", 2)
ds.DateOffsetByDays(mylink.basedate, mylink.dayoffset)
```
{: .codeblock}

If mylink.basedate contains 2011-08-18 and mylink.dayoffset contains the value -31, then the two following functions are equivalent, and return the date 2011-07-18.

```
ds.DateOffsetByDays("2011-08-18", -31)
ds.DateOffsetByDays(mylink.basedate, mylink.dayoffset)
```
{: .codeblock}
<br>

### HoursFromTime

Returns the hours portion of a time.

<h4>Syntax</h4>

```
ds.HoursFromTime(time (time))
```
{: .codeblock}

returns: the hours value in int8 format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 22:30:00, then the following two functions are equivalent, and return the integer value 22.

```
ds.HoursFromTime(mylink.mytime)
ds.HoursFromTime("22:30:00")
```
{: .codeblock}
<br>

### JulianDayFromDate

Returns a Julian day number from the given date.

<h4>Syntax</h4>

```
ds.JulianDayFromDate(time (time))
```
{: .codeblock}

returns: the Julian day number in int32 format, of the specified date.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-05-27, then the two following functions are equivalent, and return the value 2454614.

```
ds.JulianDayFromDate("2008-05-27")
ds.JulianDayFromDate(mylink.mydate)
```
{: .codeblock}
<br>

### MicroSecondsFromTime

Returns the microsecond portion of a time.

<h4>Syntax</h4>

```
ds.MicroSecondsFromTime(time (time))
```
{: .codeblock}

returns: the microsecond value of the time, in int32 format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 22:30:00.32, then the following function returns the value 320000:

```
ds.MicroSecondsFromTime(mylink.mytime)
```
{: .codeblock}
<br>

### MidnightSecondsFromTime

Returns the number of seconds from midnight to the given time.

<h4>Syntax</h4>

```
ds.MidnightSecondsFromTime(time (time))
```
{: .codeblock}

returns: the seconds value from midnight to the time, in int8 format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 00:30:52, then the two following functions are equivalent, and return the value 1852:

```
ds.MidnightSecondsFromTime("00:30:52")
ds.MidnightSecondsFromTime(mylink.mytime)
```
{: .codeblock}
<br>

### MinutesFromTime

Returns the minutes portion of a time.

<h4>Syntax</h4>

```
ds.MinutesFromTime(time (time))
```
{: .codeblock}

returns: the minutes value of the time, in int8 format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 22:30:52, then the two following functions are equivalent, and return the value 30:

```
ds.MinutesFromTime("22:30:52")
ds.MinutesFromTime(mylink.mytime)
```
{: .codeblock}
<br>

### MonthDayFromDate

Returns the day of the month from the given date.

<h4>Syntax</h4>

```
ds.MonthDayFromDate(date (date))
```
{: .codeblock}

returns: the day of the month from the given date in int8 format.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions are equivalent, and return the value 18:

```
ds.MonthDayFromDate("2008-08-18")
ds.MonthDayFromDate(mylink.mydate)
```
{: .codeblock}
<br>

### MonthFromDate

Returns the month number from the given date.

<h4>Syntax</h4>

```
ds.MonthFromDate(date (date))
```
{: .codeblock}

returns: the number of the month of format int8.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions both return the value 8:

```
ds.MonthFromDate("2008-08-18")
ds.MonthFromDate(mylink.mydate)
```
{: .codeblock}

<br>

### WeekdayFromDate

Returns the day number of the week since the given date. Can specify the day that is regarded as the first in the week, and if not specified, it is Sunday by default.

<h4>Syntax</h4>

```
ds.WeekdayFromDate(date (date), [origin_day (string)])
```
{: .codeblock}

returns: the day of the week since the given date in int8 format.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions are equivalent, and return the value 1:

```
ds.WeekdayFromDate("2008-08-18")
ds.WeekdayFromDate(mylink.mydate)
```
{: .codeblock}

If `mylink.mydate` contains the date 2008-08-18, and `mylink.origin_day` contains "saturday", then the following functions are equivalent, and return the value 2:

```
ds.WeekdayFromDate("2008-08-18", "saturday")
ds.WeekdayFromDate("2008-08-18", "sat")
ds.WeekdayFromDate(mylink.mydate, mylink.origin_day)
```
{: .codeblock}

<br>

### NextWeekdayFromDate

Returns the date of the specified day of the week soonest after the source date. The day of the week is specified as the full name, for example, thursday, or a three-letter abbreviation, for example, "thu".

<h4>Syntax</h4>

```
ds.NextWeekdayFromDate(sourcedate (date), day_of_week (string))
```
{: .codeblock}

returns: the day of the month from the given date.

<h4>Examples</h4>

If `mylink.mysourcedate` contains the date 2008-08-18 and the day of the week that is specified is Thursday, then the two following functions are equivalent, and return the value 2008-08-21:

```
ds.NextWeekdayFromDate("2008-08-18", "thursday")
ds.NextWeekdayFromDate(mylink.mysourcedate, "thu")
```
{: .codeblock}
<br>

### NthWeekdayFromDate

Returns the date of the specified day of the week offset by the specified number of weeks from the source date. The day of the week is specified as the full name, for example, thursday, or a three-letter abbreviation, for example, thu. The offset values can be positive, negative, or zero.

<h4>Syntax</h4>

```
ds.NthWeekdayFromDate(basedate (date), day_of_week (string), week_offset (int32))
```
{: .codeblock}

returns: the date of the specified weekday offset by weeks from the specified date.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2009-08-18 and Thursday is specified with an offset of 1, then the two following functions are equivalent, and return the value 2009-08-20. The first occurrence of Thursday is returned. In the proceeding example, the Thursday occurs in the same week as the date 2009-08-18. The date 2009-08-18 is a Tuesday.

```
ds.NthWeekdayFromDate("2009-08-18", "thursday", 1)
ds.NthWeekdayFromDate(mylink.mydate, "thu", 1)
```
{: .codeblock}

If `mylink.mydate` contains the date 2009-08-18 and Thursday is specified with an offset of -2, then the two following functions are equivalent, and return the value 2009-08-06. The occurrence of the Thursday that is two Thursdays past is returned.

```
ds.NthWeekdayFromDate("2009-08-18", "thursday", -2)
ds.NthWeekdayFromDate(mylink.mydate, "thu", -2)
```
{: .codeblock}
<br>

### PreviousWeekdayFromDate

Returns the date of the specified day of the week that is the most recent day before the source date. The day of the week is specified as the full name, for example, thursday, or a three-letter abbreviation, for example, "thu".

<h4>Syntax</h4>

```
ds.PreviousWeekdayFromDate(sourcedate (date), day_of_week (string))
```
{: .codeblock}

returns: the date of the most recent weekday from the specified date.

<h4>Examples</h4>

If `mylink.mysourcedate` contains the date 2008-08-18 and Thursday is specified, then the two following functions are equivalent, and return the value 2008-08-14:

```
ds.PreviousWeekdayFromDate("2008-08-18", "thursday")
ds.PreviousWeekdayFromDate(mylink.mysourcedate, "thu")
```
{: .codeblock}
<br>

### SecondsFromTime

Returns the seconds portion of a time.

<h4>Syntax</h4>

```
ds.SecondsFromTime(time (time))
```
{: .codeblock}

returns: the seconds value of the time in dfloat format.

<h4>Examples</h4>

If `mylink.mytime` contains the time 22:30:52, then the two following functions are equivalent, and return the value 52:

```
ds.SecondsFromTime("22:30:52")
ds.SecondsFromTime(mylink.mytime)
```
{: .codeblock}
<br>

### SecondsSinceFromTimestamp

Returns the number of seconds between two time stamp objects.

<h4>Syntax</h4>

```
ds.SecondsSinceFromTimestamp(timestamp (timestamp), timestamp_base_string (string))
```
{: .codeblock}

returns: the seconds value in dfloat format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the time stamp 2008-08-18 22:30:52, and `mylink.mytimestamp_base` contains the time stamp 2008-08-19 22:30:52, then the two following functions are equivalent, and return the value -86400:

```
ds.SecondsSinceFromTimestamp("2008-08-18 22:30:52","2008-08-19 22:30:52")
ds.SecondsSinceFromTimestamp(mylink.mytimestamp, mylink.mytimestamp_base)
```
{: .codeblock}
<br>

### SecondsSinceFromTimestamp2

Returns the number of seconds between two time stamp objects.

<h4>Syntax</h4>

```
ds.SecondsSinceFromTimestamp2(time stamp (timestamp), timestamp_base_object (timestamp))
```
{: .codeblock}

returns: the seconds value in dfloat format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the time stamp 2008-08-18 22:30:52, and `mylink.mytimestamp_base` contains the time stamp 2008-08-19 22:30:52, then the two following functions are equivalent, and return the value -86400:

```
ds.SecondsSinceFromTimestamp2("2008-08-18 22:30:52","2008-08-19 22:30:52")
ds.SecondsSinceFromTimestamp2(mylink.mytimestamp, mylink.mytimestamp_base)
```
{: .codeblock}
<br>

### Time

Returns a string value expressing the internal time of day. The internal time is the number of seconds that have passed since midnight to the nearest thousandth of a second (local time).

<h4>Syntax</h4>

```
ds.Time()
```
{: .codeblock}

returns: the resulting time of format string.

<h4>Examples</h4>

If the current time is 11:17:43:19, the following code returns 40663.842:

```
ds.Time()
```
{: .codeblock}
<br>

### TimeDate

Returns the system time and date as a formatted string.

<h4>Syntax</h4>

```
ds.TimeDate()
```
{: .codeblock}

returns: the system time and date in string format.

<br>

### TimeFromComponents

Returns a date type time from the given hours, minutes, seconds, and microseconds as int32.

<h4>Syntax</h4>

```
ds.TimeFromComponents(hours (int32), minutes (int32), seconds (int32), microseconds (int32))
```
{: .codeblock}

returns: the time in date type.

<h4>Examples</h4>

If `mylink.hourcol` contains the value 10, mylink.mincol contains the value 12, mylink.seccol contains the value 2, and `mylink.mseccol` contains 0, then the two following functions are equivalent, and return the time 10:12:02:

```
ds.TimeFromComponents(10, 12, 2, 0)
ds.TimeFromComponents(mylink.hourcol, mylink.mincol, mylink.seccol, mylink.mseccol)
```
{: .codeblock}
<br>

### TimeFromMidnightSeconds

Returns the system time in time format.

<h4>Syntax</h4>

```
ds.TimeFromMidnightSeconds(seconds (time))
```
{: .codeblock}

returns: the seconds since midnight in time format.

<h4>Examples</h4>

If `mylink.mymidnightseconds` contains the value 240, then the two following functions are equivalent, and return the value 00:04:00:

```
ds.TimeFromMidnightSeconds(240)
ds.TimeFromMidnightSeconds(mylink.mymidnightseconds)
```
{: .codeblock}
<br>

### TimeOffsetByComponents

Returns the time, with offsets applied from the base time with hour offset, minute offset, and second offset, each given as separate values. The seconds offset can include partial seconds.

<h4>Syntax</h4>

```
ds.TimeOffsetByComponents(basetime (time), hour_offset (int32), minute_offset (int32), second_offset (dfloat))
```
{: .codeblock}

returns: the time offset by specified values.

<h4>Examples</h4>

If `mylink.basetime` contains 14:05:29 and `mylink.houros` contains the value 2, `mylink.minos` contains the value 0, `mylink.secos` contains the value 20, then the two following functions are equivalent, and return the time 16:05:49.

```
ds.TimeOffsetByComponents("14:05:29", 2, 0, 20)
ds.TimeOffsetByComponents(mylink.basetime, mylink.houros, mylink.minos, mylink.secos)
```
{: .codeblock}
<br>

### TimeOffsetBySeconds

Returns the given time, with offsets applied from the base time with seconds offset. The seconds offset can include partial seconds.

<h4>Syntax</h4>

```
ds.TimeOffsetBySeconds(basetime (time), second_offset (dfloat))
```
{: .codeblock}

returns: the time with seconds offset by specified value.

<h4>Examples</h4>

If `mylink.basetime` contains 14:05:29.30 and `mylink.secos` contains the value 2.5, then the two following functions are equivalent, and return the time 14:05:31.

```
ds.TimeOffsetBySeconds("14:05:29.30", 2.5)
ds.TimeOffsetBySeconds(mylink.basetime, mylink.secos)
```
{: .codeblock}
<br>

### TimestampFromDateTime

Returns a time stamp from the given date and time.

<h4>Syntax</h4>

```
ds.TimestampFromDateTime(date (date), time (time))
```
{: .codeblock}

returns: the timestamp of the given date and time.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18 and `mylink.mytime` contains the time 22:30:52, then the two following functions are equivalent, and return the time stamp 2008-08-18 22:30:52:

```
ds.TimestampFromDateTime("2008-08-18","22:30:52")
ds.TimestampFromDateTime(mylink.mydate, mylink.mytime)
```
{: .codeblock}
<br>

### TimestampFromSecondsSince

Returns a time stamp that is derived from the number of seconds from the base time stamp object.

<h4>Syntax</h4>

```
ds.TimestampFromSecondsSince(seconds (dfloat), [base_timestamp_object (string)])
```
{: .codeblock}

returns: the timestamp derived from the given value of seconds.

<h4>Examples</h4>

If `mylink.myseconds` contains the value 2563 and `mylink.timestamp_base` contains the time stamp 2008-08-18 22:30:52, then the two following functions are equivalent, and return the time stamp 2008-08-18 23:13:35:

```
ds.TimestampFromSecondsSince(2563,"2008-08-18 22:30:52")
ds.TimestampFromSecondsSince(mylink.myseconds,mylink.timestamp_base)
```
{: .codeblock}
<br>

### TimestampFromSecondsSince2

Returns a time stamp that is derived from the number of seconds from the base time stamp object.

<h4>Syntax</h4>

```
ds.TimestampFromSecondsSince2(seconds (dfloat), [base_timestamp_object (timestamp)])
```
{: .codeblock}

returns: the timestamp derived from the given value of seconds.

<h4>Examples</h4>

If `mylink.myseconds` contains the value 2563 and `mylink.timestamp_base` contains the time stamp 2008-08-18 22:30:52, then the two following functions are equivalent, and return the time stamp 2008-08-18 23:13:35:

```
ds.TimestampFromSecondsSince2(2563,"2008-08-18 22:30:52")
ds.TimestampFromSecondsSince2(mylink.myseconds, mylink.timestamp_base)
```
{: .codeblock}
<br>

### TimestampFromTimet

Returns a time stamp from the given UNIX `time_t` string value.

<h4>Syntax</h4>

```
ds.TimestampFromTimet(timet_string (int32))
```
{: .codeblock}

returns: the timestamp derived from the given value of seconds.

<h4>Examples</h4>

If `mylink.mytimet` contains the value 1234567890, then the two following functions are equivalent, and return the time stamp 2009-02-13 23:31:30:

```
ds.TimestampFromTimet(1234567890)
ds.TimestampFromTimet(mylink.mytimet)
```
{: .codeblock}
<br>

### TimestampFromTime2

Returns a time stamp from the given time and timestamp objects. The value in the time object overwrites the time value in the time stamp object so that only the date part is used from the time stamp.

<h4>Syntax</h4>

```
ds.TimestampFromTime2(time (time), timestamp (timestamp))
```
{: .codeblock}

returns: the timestamp from the given time and timestamp objects.

<h4>Examples</h4>

If `mylink.mytime` contains the time 12:03:22 and `mylink.mytimestamp` contains the time stamp 2008-08-18 22:30:52, then the two following functions are equivalent, and return the time stamp 2008-08-18 12:03:22:

```
ds.TimestampFromTime2("12:03:22", "2008-08-18 22:30:52")
ds.TimestampFromTime2(mylink.mytime, mylink.mytimestamp)
```
{: .codeblock}
<br>

### TimestampOffsetByComponents

Returns the time stamp, with offsets applied from the base time stamp with year offset, month offset, day offset, hour offset, minute offset, and second offset, each given as separate values. The seconds offset can include microseconds.

<h4>Syntax</h4>

```
ds.TimestampOffsetByComponents(basetimestamp (timestamp), year_offset (int32), month_offset (int32), dayofmonth_offset (int32), hour_offset (int32), minute_offset (int32), second_offset (dfloat))
```
{: .codeblock}

returns: the timestamp offset by specified values.

<h4>Examples</h4>

If `mylink.basetimestamp` contains 2009-08-18 14:05:29 and `mylink.yearos` contains 0, `mylink.monthos` contains the value 2, `mylink.dayos` contains the value -4, `mylink.houros` contains the value 2, `mylink.minos` contains the value 0, `mylink.secos` contains the value 20, then the two following functions are equivalent, and return the time stamp 2009-10-14 16:05:49.

```
ds.TimestampOffsetByComponents("2009-08-18 14:05:29", 0, 2, -4, 2, 0, 20)
ds.TimestampOffsetByComponents(mylink.basetimestamp, mylink.houros,
mylink.minos, mylink.secos)
```
{: .codeblock}
<br>

### TimestampOffsetBySeconds

Returns the time stamp, with offsets applied from the base time stamp with seconds offset. The seconds offset can include microseconds.

<h4>Syntax</h4>

```
ds.TimestampOffsetBySeconds(basetimestamp (timestamp), second_offset (dfloat))
```
{: .codeblock}

returns: the timestamp offset by specified values in timestamp format.

<h4>Examples</h4>

If `mylink.basetimestamp` contains 2009-08-18 14:05:29 and `mylink.secos` contains the value 32760, then the two following functions are equivalent, and return the time stamp 2009-08-18 23:11:29:

```
ds.TimestampOffsetBySeconds("2009-08-18 14:05:29", 32760)
ds.TimestampOffsetBySeconds(mylink.basetimestamp, mylink.secos)
```
{: .codeblock}
<br>

### TimetFromTimestamp

Returns a UNIX time_t value from the given time stamp.

<h4>Syntax</h4>

```
ds.TimetFromTimestamp(timestamp (timestamp))
```
{: .codeblock}

returns: the UNIX time_t by given timestamp in int32 format.

<h4>Examples</h4>

If `mylink.mytimestamp` contains the value 2009-02-13 23:31:30, then the two following functions are equivalent, and return the value 1234567890:

```
ds.TimetFromTimestamp("2009-02-13 23:31:30")
ds.TimetFromTimestamp(mylink.mytimestamp)
```
{: .codeblock}
<br>



### YeardayFromDate

Returns the day number in the year from the given date.

<h4>Syntax</h4>

```
ds.YeardayFromDate(date (date))
```
{: .codeblock}

returns: the day number in int16 format.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions are equivalent, and return the value 231:

```
ds.YeardayFromDate("2008-08-18")
ds.YeardayFromDate(mylink.mydate)
```
{: .codeblock}
<br>

### YearFromDate

Returns the year from the given date.

<h4>Syntax</h4>

```
ds.YearFromDate(date (date))
```
{: .codeblock}

returns: the year number in int16 format.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions are equivalent, and return the value 2008:

```
ds.YearFromDate("2008-08-18")
ds.YearFromDate(mylink.mydate)
```
{: .codeblock}
<br>

### YearweekFromDate

Returns the week number in the year from the given date.

<h4>Syntax</h4>

```
ds.YearweekFromDate(date (date))
```
{: .codeblock}

returns: the week number in int16 format.

<h4>Examples</h4>

If `mylink.mydate` contains the date 2008-08-18, then the two following functions are equivalent, and return the value 33:

```
ds.YearweekFromDate("2008-08-18")
ds.YearweekFromDate(mylink.mydate)
```
{: .codeblock}

<br>

### Month

Returns the current month.

<h4>Syntax</h4>

```
ds.Month()
```
{: .codeblock}

returns: the current month.

<h4>Examples</h4>

The following code returns the current month in int format.

```
ds.Month()
```
{: .codeblock}

<br>

### Year

Returns the current year.

<h4>Syntax</h4>

```
ds.Year()
```
{: .codeblock}

returns: the current year in int format.

<h4>Examples</h4>

The following code returns the current year.

```
ds.Year()
```
{: .codeblock}

<br>
<!--End of date and time functions-->

## Logical functions
{: #logical}

The logical functions perform bit operations.
<br>

### BitAnd

Returns the bitwise `AND` of the two integer arguments.

<h4>Syntax</h4>

```
ds.BitAnd(number1 (uint64), number2 (uint64))
```
{: .codeblock}

returns: the bitwise `AND` in uint64 format.

<h4>Examples</h4>

If `mylink.mynumber1` contains the number 352 and mylink.mynumber2 contains the number 400, then the following two functions are equivalent, and return the value 256:

```
ds.BitAnd(352,400)
ds.BitAnd(mylink.mynumber1, mylink.mynumber2)
```
{: .codeblock}
<br>

### BitCompress

Returns the integer made from the string argument, which contains a binary representation of "1"s and "0"s.

<h4>Syntax</h4>

```
ds.BitCompress(string (string))
```
{: .codeblock}

returns: the resulting number represented by binaries of format uint64.

<h4>Examples</h4>

If `mylink.mynumber1` contains the string "0101100000", then the following two functions both return the number 352.

```
ds.BitCompress("0101100000")
ds.BitCompress(mylink.mynumber)
```
{: .codeblock}
<br>

### BitExpand

Returns a string containing the binary representation in "1"s and "0"s of the given integer.

<h4>Syntax</h4>

```
ds.BitExpand(number (uint64))
```
{: .codeblock}

returns: a string containing the binary representation of the integer.

<h4>Examples</h4>

If `mylink.mynumber1` contains the number 352, then the following two functions are equivalent, and return the string "101100000".

```
ds.BitExpand(352)
ds.BitExpand(mylink.mynumber)
```
{: .codeblock}
<br>

### BitOr

Returns the bitwise `OR` of the two integer arguments.

<h4>Syntax</h4>

```
ds.BitOr(number1 (uint64), number2 (uint64))
```
{: .codeblock}

returns: the bitwise `OR` of the two integer arguments.

<h4>Examples</h4>

If `mylink.mynumber1` contains the number 352 and mylink.mynumber2 contains the number 400, then the following two functions are equivalent, and return the value 496:

```
ds.BitOr(352,400)
ds.BitOr(mylink.mynumber1, mylink.mynumber2)
```
{: .codeblock}
<br>

### BitXOr

Returns the bitwise `Exclusive OR` of the two integer arguments.

<h4>Syntax</h4>

```
ds.BitXOr(number1 (uint64), number2 (uint64))
```
{: .codeblock}

returns: the `Exclusive OR` in uint64 format.

<h4>Examples</h4>

If `mylink.mynumber1` contains the number 352 and `mylink.mynumber2` contains the number 400, then the following two functions are equivalent, and return the value 240:

```
ds.BitXOr(352,400)
ds.BitXOr(mylink.mynumber1, mylink.mynumber2)
```
{: .codeblock}
<br>

### Not

Returns the complement of the logical value of an expression. If the value of expression is true, the `Not` function returns a value of false (0). If the value of expression is false, the `NOT` function returns a value of true (1). A numeric expression that evaluates to 0 is a logical value of false. A numeric expression that evaluates to anything else, other than the null value, is a logical true. An empty string is logically false. All other string expressions, including strings that include an empty string, spaces, or the number 0 and spaces, are logically true.

<h4>Syntax</h4>

```
ds.Not()
```
{: .codeblock}

returns: the value of `complement` in int8 format.

<h4>Examples</h4>

If `mylink.myexpression` contains the expression 5-5, then the following two functions are equivalent, and return the value 1:

```
ds.Not(5-5)
ds.Not(mylink.myexpression)
```
{: .codeblock}

If `mylink.myexpression` contains the expression 5+5, then the following two functions are equivalent, and return the value 0:

```
ds.Not(5+5)
ds.Not(mylink.myexpression)
```
{: .codeblock}
<br>

### SetBit

Returns an integer with specific bits set to a specific state, where `origfield` is the input value to perform the action on, `bitlist` is a string containing a list of comma-separated bit numbers to set the state of, and `bitstate` is either 1 or 0, indicating which state to set those bits.

<h4>Syntax</h4>

```
ds.SetBit(origfield (uint64), bitlist (string), bitstate (uint8))
```
{: .codeblock}

returns: the number with the bits set to the specified state in uint64 format.

<h4>Examples</h4>

If `mylink.origfield` contains the number 352, `mylink.bitlist` contains the list "2,4,8", and `mylink.bitstate` contains the value 1, then the following two functions are equivalent, and return the value 494:

```
ds.SetBit(356,"2,4,8",1)
ds.SetBit(mylink.origfield, mylink.bitlist, mylink.bitstate)
```
{: .codeblock}

### True

Returns the true value of 1.

<h4>Syntax</h4>

```
ds.True()
```
{: .codeblock}

returns: the integer 1.

<h4>Examples</h4>

The following code will return 1:

```
ds.True()
```
{: .codeblock}

### False

Returns the false value of 0.

<h4>Syntax</h4>

```
ds.False()
```
{: .codeblock}

returns: the integer 0.

<h4>Examples</h4>

The following code will return 0:

```
ds.False()
```
{: .codeblock}
<!--End of logical functions-->
<br>

## Mathmatical functions
{: #mathematical}

The mathematical functions perform mathematical operations.
<br>

### Abs

Returns the absolute value of any numeric expression. The absolute value of an expression is its unsigned magnitude.

<h4>Syntax</h4>

```
ds.Abs(numeric_expression (int32))
```
{: .codeblock}

returns: the absolute value of the numeric expression in dfloat format.

<h4>Examples</h4>

If `mylink.number1` contains the number 12 and `mylink.number2` contains the number 34, then the following two functions are equivalent, and return the number 22:

```
ds.Abs(12-34)
ds.Abs(mylink.mynumber1-mylink.mynumber2)
```
{: .codeblock}

If `mylink.number1` contains the number 34 and `mylink.number2` contains the number 12, then the following two functions are equivalent, and return the number 22:

```
ds.Abs(34-12)
ds.Abs(mylink.mynumber1-mylink.mynumber2)
```
{: .codeblock}
<br>

### Acos

Calculates the trigonometric arc-cosine of an expression. The expression must be a numeric value. The result is expressed in radians.

<h4>Syntax</h4>

```
ds.Acos(numeric_expression (dfloat))
```
{: .codeblock}

returns: the resulting radian in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 0.707106781, then the following two functions are equivalent, and return the value 0.7854:

```
ds.Acos(0.707106781)
ds.Acos(mylink.mynumber)
```
{: .codeblock}
<br>

### ACOS

Returns the trigonometric arc-cosine of expression. Input must be a numeric value. The result is expressed in degrees.

<h4>Syntax</h4>

```
ds.ACOS(expression (float64))
```
{: .codeblock}

returns: the angle in degrees, of float64 format.

<h4>Examples</h4>

The following code returns the value 45:

```
ds.ACOS(0.707106781)
```
{: .codeblock}
<br>

### Asin

Calculates the trigonometric arc-sine of an expression. The expression must be a numeric value. The result is expressed in radians.

<h4>Syntax</h4>

```
ds.Asin(numeric_expression (dfloat))
```
{: .codeblock}

returns: the radian result in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 0.707106781, then the following two functions are equivalent, and return the value 0.7854:

```
ds.Asin(0.707106781)
ds.Asin(mylink.mynumber)
```
{: .codeblock}
<br>

### ASIN

Returns the trigonometric sine of an expression. Input is the angle expressed in degrees.

<h4>Syntax</h4>

```
ds.ASIN(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of float64 format.

<h4>Examples</h4>

The following code returns the value 45:

```
ds.ASIN(0.707106781)
```
{: .codeblock}
<br>

### Atan

Calculates the trigonometric arc-tangent of an expression. The expression must be a numeric value. The result is expressed in radians.

<h4>Syntax</h4>

```
ds.Atan(numeric_expression (dfloat))
```
{: .codeblock}

returns: the radian result in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 135, then the following two functions are equivalent, and return the value 1.5634, which is the angle that has an arc tangent of 135:

```
ds.Atan(135)
ds.Atan(mylink.mynumber)
```
{: .codeblock}
<br>

### ATAN

Returns the trigonometric arc-tangent of expression. Input must be a numeric value. The result is expressed in degrees.

<h4>Syntax</h4>

```
ds.ATAN(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of dfloat format.

<h4>Examples</h4>

The following code returns the value 45:

```
ds.ATAN(1)
```
{: .codeblock}
<br>

### Atan2

Calculates the trigonometric arc-tangent of the two inputs by using the signs of the two inputs to determine the quadrant of the result. The inputs must be numeric values. The result is expressed in radians.

<h4>Syntax</h4>

```
ds.Atan2(numeric_expression (dfloat, dfloat))
```
{: .codeblock}

returns: the radian result in dfloat format.

<h4>Examples</h4>

If `mylink.number1` contains the number 10.0 and `mylink.number2` contains the number -10.0, then the following two functions are equivalent, and return the value 2.3562:

```
ds.Atan2(10.0, -10.0)
ds.Atan2(mylink.mynumber1, mylink.mynumber2)
```
{: .codeblock}
<br>

### Ceil

Calculates the smallest integer value greater than or equal to the given decimal value.

<h4>Syntax</h4>

```
ds.Ceil(number (dfloat))
```
{: .codeblock}

returns: the smallest integer value in int32.

<h4>Examples</h4>

If `mylink.number` contains the number 2355.66, then the following two functions are equivalent, and return the value 2356:

```
ds.Ceil(2355.66)
ds.Ceil(mylink.mynumber)
```
{: .codeblock}
<br>

### Cos

Calculates the trigonometric cosine of an expression. The expression must be a numeric value. The expression must produce a numeric value that is the angle in radians.

<h4>Syntax</h4>

```
ds.Cos(radians (dfloat))
```
{: .codeblock}

returns: the angle in radians, of dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 0.785398, then the following two functions are equivalent, and return the value 0.7071:

```
ds.Cos(0.785398)
ds.Cos(mylink.mynumber)
```
{: .codeblock}
<br>

### COS

Returns the trigonometric cosine of an angle. The expression is an angle expressed as a numeric value in degrees.

<h4>Syntax</h4>

```
ds.COS(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of float64 format.

<h4>Examples</h4>

The following code returns the value 0.7071:

```
ds.COS(45)
```
{: .codeblock}
<br>

### Cosh

Calculates the hyperbolic cosine of an expression. The expression must be a numeric value.

<h4>Syntax</h4>

```
ds.Cosh(number (dfloat))
```
{: .codeblock}

returns: the resulting cosine in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 2, then the following two functions are equivalent, and return the value 3.7622:

```
ds.Cosh(2)
ds.Cosh(mylink.mynumber)
```
{: .codeblock}
<br>

### Div

Calculates the hyperbolic cosine of an expression. The expression must be a numeric value.

<h4>Syntax</h4>

```
ds.Div(dividend (dfloat), divisor (dfloat))
```
{: .codeblock}

returns: the resulting cosine in dfloat format.

<h4>Examples</h4>

If `mylink.dividend` contains the number 100, and `mylink.divisor` contains the number 25, then the following two functions are equivalent, and return the value 4:

```
ds.Div(100,25)
ds.Div(mylink.dividend, mylink.divisor)
```
{: .codeblock}
<br>

### Exp

Calculates the result of base *e* raised to the power designated by the value of the expression. The value of *e* is approximately 2.71828. The expression must evaluate to a numeric value.

<h4>Syntax</h4>

```
ds.Exp(number (dfloat))
```
{: .codeblock}

returns: the resulting *e* raised to the specified power in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 5, then the following two functions are equivalent, and return the value 54.5982:

```
ds.Exp(5-1)
ds.Exp(mylink.number-1)
```
{: .codeblock}
<br>

### Fabs

Calculates the absolute value of the given float value.

<h4>Syntax</h4>

```
ds.Fabs(number (dfloat))
```
{: .codeblock}

returns: the absolute value of the float number.

<h4>Examples</h4>

If `mylink.number` contains the number -26.53, then the following two functions are equivalent, and return the value 26.53:

```
ds.Fabs(-26.53)
ds.Fabs(mylink.number)
```
{: .codeblock}
<br>

### Floor

Calculates the largest integer value less than or equal to the given decimal value.

<h4>Syntax</h4>

```
ds.Floor(number (dfloat))
```
{: .codeblock}

returns: the largest integer less than or equal to the decimal value in int32 format.

<h4>Examples</h4>

If `mylink.number` contains the number 203.25, then the following two functions are equivalent, and return the value 203:

```
ds.Floor(203.25)
ds.Floor(mylink.number)
```
{: .codeblock}
<br>

### Ldexp

Returns a dfloat value from multiplying the mantissa by 2 raised to the power of the exponent.

<h4>Syntax</h4>

```
ds.Ldexp(mantissa (dfloat), exponent (int32))
```
{: .codeblock}

returns: the resulting mantissa in dfloat format.

<h4>Examples</h4>

If `mylink.mantissa` contains the number 2, and `mylink.exponent` contains the number 3, then the following two functions are equivalent, and return the value 16:

```
ds.Ldexp(2,3)
ds.Ldexp(mylink.mantissa, mylink.exponent)
```
{: .codeblock}
<br>

### Llabs

Calculates the absolute value of the given integer value.

<h4>Syntax</h4>

```
ds.Llabs(number (integer))
```
{: .codeblock}

returns: the absolute value of the given integer as an unsigned integer.

<h4>Examples</h4>

If `mylink.number` contains the number -26, then the following two functions are equivalent, and return the value 26.

```
ds.Llabs(-26)
ds.Llabs(mylink.number)
```
{: .codeblock}
<br>

### Ln

Calculates the natural logarithm of an expression in base *e*. The value of *e* is approximately 2.71828. The expression must evaluate to a numeric value greater than 0.

<h4>Syntax</h4>

```
ds.Ln(number (dfloat))
```
{: .codeblock}

returns: the resulting logarithm of the *e* based expression.

<h4>Examples</h4>

If `mylink.number` contains the number 6, then the following two functions are equivalent, and return the value 1.7918:

```
ds.Ln(6)
ds.Ln(mylink.number)
```
{: .codeblock}
<br>

### Log10

Returns the logarithm in base 10 of the given value.

<h4>Syntax</h4>

```
ds.Log10(number (dfloat))
```
{: .codeblock}

returns: the resulting base 10 logarithm in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 6, then the following two functions are equivalent, and return the value 1.7782:

```
ds.Log10(6)
ds.Log10(mylink.number)
```
{: .codeblock}
<br>

### Max

Returns the greater of the two argument values.

<h4>Syntax</h4>

```
ds.Max(number1 (int32), number2(int32))
```
{: .codeblock}

returns: the greater of the two integers in int32 format.

<h4>Examples</h4>

If `mylink.number1` contains the number 6, and `mylink.number1` contains the number 101, then the following two functions are equivalent, and return the value 101:

```
ds.Max(6,101)
ds.Max(mylink.number1, mylink.number2)
```
{: .codeblock}
<br>

### Min

Returns the lower of the two argument values.

<h4>Syntax</h4>

```
ds.Min(number1 (int32), number2(int32))
```
{: .codeblock}

returns: the lesser of the two integers.

<h4>Examples</h4>

If `mylink.number1` contains the number 6, and `mylink.number1` contains the number 101, then the following two functions are equivalent, and return the value 6:

```
ds.Min(6,101)
ds.Min(mylink.number1, mylink.number2)
```
{: .codeblock}
<br>

### Mod

Calculates the modulo (the remainder) of two expressions (dividend, divisor).

<h4>Syntax</h4>

```
ds.Mod(dividend (int32), divisor (int32))
```
{: .codeblock}

returns: the resulting modulo in int32 format.

<h4>Examples</h4>

If `mylink.dividend` contains the number 115, and `mylink.divisor` contains the number 25, then the following two functions are equivalent, and return the value 15:

```
ds.Mod(115,25)
ds.Mod(mylink.dividend, mylink.divisor)
```
{: .codeblock}
<br>

### Neg

Negates a number.

<h4>Syntax</h4>

```
ds.Neg(number (dfloat))
```
{: .codeblock}

returns: the resulting negated number in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 123, then the following two functions are equivalent, and return the value -123:

```
ds.Neg(123)
ds.Neg(mylink.number)
```
{: .codeblock}
<br>

### Pwr

Calculates the value of an expression when raised to a specified power (expression, power).

<h4>Syntax</h4>

```
ds.Pwr(expression (dfloat), power (dfloat))
```
{: .codeblock}

returns: the resulting number raised to the specified power in dfloat format.

<h4>Examples</h4>

If `mylink.expression` contains the number 2, and mylink.power contains the number 3, then the following two functions are equivalent, and return the value 8:

```
ds.Pwr(2,3)
ds.Pwr(mylink.expression, mylink.power)
```
{: .codeblock}
<br>

### Rand

Returns a pseudorandom integer between 0 and 2<sup>32</sup>-1.

<h4>Syntax</h4>

```
ds.Rand()
```
{: .codeblock}

returns: the resulting random integer in uint32 format.

<h4>Examples</h4>

Use this function to generate a pseudorandom number:

```
ds.Rand()
```
{: .codeblock}
<br>

### Random

Returns a pseudorandom integer between 0 and 2<sup>32</sup>-1.

<h4>Syntax</h4>

```
ds.Random()
```
{: .codeblock}

returns: the resulting random integer in uint32 format.

<h4>Examples</h4>

Use this function to generate a random number:

```
ds.Random()
```
{: .codeblock}
<br>

### Rnd

Generates any positive or negative random integer or 0. Takes the the total number of integers as input, including 0, from which the random number can be selected. That is, if n is the value of numeric_expression, the random number is generated from the numbers 0 through (n - 1).

<h4>Syntax</h4>

```
ds.Rnd(numeric_expression (int))
```
{: .codeblock}

returns: a random number from 0 to `(numeric_expression - 1)` in int format.

<h4>Examples</h4>

The following code returns a random number from 0-19.

```
ds.Rnd(20)
```
{: .codeblock}
<br>

### Sin

Calculates the trigonometric sine of an expression. The expression must be a numeric value. The expression must produce a numeric value that is the angle in radians.

<h4>Syntax</h4>

```
ds.Sin(radians (dfloat))
```
{: .codeblock}

returns: the resulting angle in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 0.785398, then the following two functions are equivalent, and return the value 0.7071:

```
ds.Sin(0.785398)
ds.Sin(mylink.mynumber)
```
{: .codeblock}
<br>

### SIN

Returns the trigonometric sine of an expression. Input is the angle expressed in degrees.

<h4>Syntax</h4>

```
ds.SIN(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of dfloat format.

<h4>Examples</h4>

The following code returns the value 0.7071:

```
ds.SIN(45)
```
{: .codeblock}
<br>

### Sinh

Calculates the hyperbolic sine of an expression. The expression must be a numeric value.

<h4>Syntax</h4>

```
ds.Sinh(number (dfloat))
```
{: .codeblock}

returns: the resulting sine in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 2, then the following two functions are equivalent, and return the value 3.6269:

```
ds.Sinh(2)
ds.Sinh(mylink.mynumber)
```
{: .codeblock}
<br>

### Sqrt

Calculates the square root of a number.

<h4>Syntax</h4>

```
ds.Sqrt(number (dfloat))
```
{: .codeblock}

returns: the resulting square root of the number in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 450, then the following two functions are equivalent, and return the value 21.2132:

```
ds.Sqrt(450)
ds.Sqrt(mylink.mynumber)
```
{: .codeblock}
<br>

### Tan

Calculates the trigonometric tangent of an expression. The expression must produce a numeric value that is the angle in radians.

<h4>Syntax</h4>

```
ds.Tan(radians (dfloat))
```
{: .codeblock}

returns: the resulting tangent in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 0.7853981, then the following two functions are equivalent, and return the value 1:

```
ds.Tan(0.7853981)
ds.Tan(mylink.mynumber)
```
{: .codeblock}
<br>

### TAN

Returns the TAN function to return the trigonometric tangent of the input. The input represents an angle expressed in degrees.

<h4>Syntax</h4>

```
ds.TAN(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of float64 format.

<h4>Examples</h4>

The following code returns the value 1:

```
ds.TAN(45)
```
{: .codeblock}
<br>

### ATAN

Returns the trigonometric arc-tangent of expression. Input must be a numeric value. The result is expressed in degrees.

<h4>Syntax</h4>

```
ds.ATAN(expression(float64))
```
{: .codeblock}

returns: the angle in degrees, of float64 format.

<h4>Examples</h4>

The following code returns the value 45:

```
ds.ATAN(1)
```
{: .codeblock}
<br>

### Tanh

Calculates the hyperbolic tangent of an expression. The expression must be a numeric value.

<h4>Syntax</h4>

```
ds.Tanh(number (dfloat))
```
{: .codeblock}

returns: the resulting tangent in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 2, then the following two functions are equivalent, and return the value 0.964028:

```
ds.Tanh(2)
ds.Tanh(mylink.mynumber)
```
{: .codeblock}
<!--End of mathematical functions-->
<br>

## Number functions
{: #number}

Use the number functions to extract the mantissa from a decimal or floating point number. The **Number** category in the expression editor also contains the type casting functions, which you can use to cast numbers as double, float, or integer data types.

The transformer functions `AsDouble()`, `AsFloat()`, and `AsInteger()` behave differently than other transformer data conversions functions when they are used in derivations where the result is a string. This is because the transformer compiler does not convert the function result for these functions to a string.
<br>

### AsDouble

Treat the given number as a double.

<h4>Syntax</h4>
<!--In the JSON files, there is no input-->
```
ds.AsDouble(number (int, float etc.))
```
{: .codeblock}

returns: the number in double format.

<h4>Examples</h4>

In the following expression, the input `mynumber `contains an integer, but the function outputs a double. If `mylink.mynumber` contains the value 56, then the following two functions are equivalent, and return the value 12.963:

```
ds.AsDouble(56/4.32)
ds.AsDouble(mylink.mynumber/4.32)
```
{: .codeblock}
<br>

### AsFloat

Treat the given number as a float.

<h4>Syntax</h4>
<!--In the JSON files, there is no input-->
```
ds.AsFloat(number (int, double etc.))
```
{: .codeblock}

returns: the number in float format.

<h4>Examples</h4>

In the following expression, the input `mynumber` contains an integer, but the function outputs a float. If `mylink.mynumber` contains the value 56, then the following two functions are equivalent, and return the value 12.963:

```
ds.AsFloat(56/4.32)
ds.AsFloat(mylink.mynumber/4.32)
```
{: .codeblock}
<br>

### AsInteger

Treat the given number as an integer. But there a difference in behavior when a decimal is assigned to an integer versus a float or a double being assigned to an integer. If the conversion is from float or a double to an integer, it is a simple assignment to an integer. In case of decimal `AsInteger()`, function is invoked and rounds the output towards nearest value.

<h4>Syntax</h4>
<!--In the JSON files, there is no input-->
```
ds.AsInteger(number (float, double etc.))
```
{: .codeblock}

returns: the number in integer format.

<h4>Examples</h4>

In the following expression, the input value 12.962963 has a type Double. Though the value is of type Double, the function outputs an integer. Hence it is a simple assignment to an integer and function returns the value 12:

```
ds.AsInteger(12.962963)
```
{: .codeblock}

In the following expression, the calculations like (56/4.32) are treated as a type Decimal and `AsInteger()` function call invoked will round towards the nearest value and returns the value 13:

```
ds.AsInteger(56/4.32)
```
{: .codeblock}
<br>

### FIX

Converts a numeric value to a floating-point number with a specified precision number. If number evaluates to the null value, null is returned. The precision value is a numerical value that corresponds to the number of digits of precision in the floating-point number. The default precision is 4. The mode value is a flag that specifies how excess digits are handled. If mode is either 0 or not specified, excess digits are rounded off. If mode is anything other than 0, excess digits are truncated.

<h4>Syntax</h4>

```
ds.FIX(numeric_expression (string), precision (int8), mode (int32))
```
{: .codeblock}

returns: the converted number of format dfloat.

<h4>Examples</h4>

The following code returns the number 37.7363.

```
ds.FIX("37.73629273")
```
{: .codeblock}
<br>

### MantissaFromDecimal

Returns the mantissa from the given decimal.

<h4>Syntax</h4>
<!--In the JSON files, there is no input-->
```
ds.MantissaFromDecimal(number (decimal))
```
{: .codeblock}

returns: the mantissa in dfloat format.

<h4>Examples</h4>

If mylink.number contains the number 243.7675, then the following two functions are equivalent, and return the value 7675:

```
ds.MantissaFromDecimal(243.7675)
ds.MantissaFromDecimal(mylink.mynumber)
```
{: .codeblock}
<br>

### MantissaFromDFloat

Returns the mantissa from the given dfloat.

<h4>Syntax</h4>
<!--In the JSON files, there is no input-->
```
ds.MantissaFromDFloat(number (dfloat))
```
{: .codeblock}

returns: the mantissa in dfloat format.

<h4>Examples</h4>

If `mylink.number` contains the number 1.234412000000000010E+4, then the following function returns the value 1:

```
ds.MantissaFromDFloat(mylink.mynumber)
```
{: .codeblock}

### Real

Converts a number in string to type floating-point without loss of accuracy.

<h4>Syntax</h4>

```
ds.Real(numeric_expression (string))
```
{: .codeblock}

returns: the converted number of format dfloat.

<h4>Examples</h4>

The following code returns the number 1.23.

```
ds.Real("1.23")
```
{: .codeblock}
<br>
<!--End of number functions-->

## Raw functions
{: #raw}

Use the Raw function to obtain the length of the data in a column containing raw data.
<br>

### RawLength

Returns the length of a raw string.

<h4>Syntax</h4>

```
ds.RawLength(input string (string))
```
{: .codeblock}

returns: the length of the raw string in int32 format.

<h4>Examples</h4>

If `mylink.rawdata` contains the raw data from a bitmap, then the following function returns the size of the bitmap in bytes:

```
ds.RawLength(mylink.rawdata)
```
{: .codeblock}
<!--End of raw functions-->
<br>

## String functions
{: #string}

Use these functions for string related functions in an expression.
<br>

### AlNum

Checks whether the given string contains only alphanumeric characters.

<h4>Syntax</h4>

```
ds.AlNum(string (string))
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Example</h4>

If `mylink.mystring1` contains the string "OED_75_9*E", then the following function would return the value 0 (false).

```
ds.AlNum(mylink.mystring1)
```
{: .codeblock}

If `mylink.mystring2` contains the string "12redroses", then the following function would return the value 1 (true).

```
ds.AlNum(mylink.mystring2)
```
{: .codeblock}
<br>

### Alpha

Checks whether the given string contains only alphabetic characters.

<h4>Syntax</h4>

```
ds.Alpha(string (string))
```
{: .codeblock}

returns: a result of int8 type, 1 if the input is valid for the given type, and 0 otherwise.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "12redroses", then the following function would return the value 0 (false).

```
ds.Alpha(mylink.mystring1)
```
{: .codeblock}

If `mylink.mystring2` contains the string "twelveredroses", then the following function would return the value 1 (true).

```
ds.Alpha(mylink.mystring2)
```
{: .codeblock}
<br>

### Cats

Concatenates two strings.

<h4>Syntax</h4>

```
ds.Cats(str1 (string), str2 (string))
```
{: .codeblock}

returns: the resulting concatenated string.

<h4>Examples</h4>

The following code returns "ABC123".

```
ds.Cats("ABC", "123")
```
{: .codeblock}
<br>

### Change

Replaces the given substring in an expression with a replacement string.

If the substring argument is an empty string, the value of the expression argument is returned.

If the value of the replacement argument is an empty string, all occurrences of the substring starting from the position indicated by the value of the begin argument are removed. If the value of the occurrence argument is less than or equal to 0, all occurrences starting from the position indicated by the value of the begin argument are replaced. Otherwise, the number of occurrences that are replaced is indicated by the value of the occurrence argument, starting from the position indicated by the value of the begin argument. If the value of the begin argument is less than or equal to 1, the replacement starts from the first occurrence. Otherwise, the replacement starts from the position indicated by the value of thebegin argument.

<h4>Syntax</h4>

```
ds.Change(expression (string), substring (string), replacement (string), [occurrence (int32), [begin (int32)]])
```
{: .codeblock}

returns: the new string with all substrings replaced.

<h4>Examples</h4>
</b>
If `mylink.mystring` contains the expression "aaabbbcccbbb", then the following function returns the string "aaaZZZcccZZZ".

```
ds.Change(mylink.mystring,"bbb","ZZZ")
```
{: .codeblock}

If `mylink.mystring` contains the expression "ABC" and the substring is empty, then the following function returns the string "ABC".

```
ds.Change(mylink.mystring,"","ZZZ")
```
{: .codeblock}

If `mylink.mystring` contains the expression "aaabbbcccbbb" and the replacement is empty, then the following function returns the string "aaaccc".

```
ds.Change(mylink.mystring, "bbb", "")
```
{: .codeblock}
<br>

### CompactWhiteSpace

Returns the string after reducing all consecutive white space to a single space.

<h4>Syntax</h4>

```
ds.CompactWhiteSpace(string (string))
```
{: .codeblock}

returns: the resulting string with reduced white spaces.

<h4>Examples</h4>

If `mylink.mystring` contains the string "too&nbsp;&nbsp;&nbsp;many&nbsp;&nbsp;&nbsp;&nbsp;spaces", then the following function returns the string "too many spaces":

```
ds.CompactWhiteSpace(mylink.mystring)
```
{: .codeblock}
<br>

### Compare

Compares two strings for sorting. The comparison can be left-aligned (the default) or right-aligned. A right-aligned comparison compares numeric substrings within the specified strings as numbers.

The numeric strings must occur at the same character position in each string. For example, a right-aligned comparison of the strings AB100 and AB99 indicates that AB100 is greater than AB99 since 100 is greater than 99. A left-aligned comparison of the strings AC99 and AB100 indicates that AC99 is greater since C is greater than B.

<h4>Syntax</h4>

```
ds.Compare(string1 (string), string2 (string), [justification ("L" or "R")] )
```
{: .codeblock}

returns: a result of int8 type, -1 if string1 is less than string2, 0 if both strings are the same, 1 if string1 is greater than string2.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "AB99" and mylink.mystring2 contains the string "AB100", then the following function returns the result 1.

```
ds.Compare(mylink.mystring1, mylink.mystring2, "L")
```
{: .codeblock}

If `mylink.mystring1` contains the string "AB99" and mylink.mystring2 contains the string "AB100", then the following function returns the result -1.

```
ds.Compare(mylink.mystring1, mylink.mystring2, "R")
```
{: .codeblock}
<br>

### CompareNoCase

Compares two strings for sorting, ignoring their cases.

<h4>Syntax</h4>

```
ds.CompareNoCase(string1 (string), string2 (string))
```
{: .codeblock}

returns: a result of int8 type, -1 if string1 is less than string2, 0 if both strings are the same, and 1 if string1 is greater than string2.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "Chocolate Cake" and `mylink.mystring2` contains the string "chocolate cake", then the following function returns the result 0.

```
ds.CompareNoCase(mylink.mystring1, mylink.mystring2)
```
{: .codeblock}
<br>

### CompareNum

Compares the first *n* characters of two strings, *n* being specified by the user.

<h4>Syntax</h4>

```
ds.CompareNum(string1 (string), string2 (string), length (int16))
```
{: .codeblock}

returns: a result of int8 type, -1 if string1 is less than string2, 0 if both strings are the same, 1 if string1 is greater than string2.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "Chocolate" and `mylink.mystring2` contains the string "Choccy Treat", then the following function returns the result 0.

```
ds.CompareNum(mylink.mystring1, mylink.mystring2,4)
```
{: .codeblock}
<br>

### CompareNumNoCase

Compares the first *n* characters of two strings, ignoring their case, *n* being specified by the user.

<h4>Syntax</h4>

```
ds.CompareNumNoCase(string1 (string), string2 (string), length (int16))
```
{: .codeblock}

returns: a result of int8 type, -1 if string1 is less than string2, 0 if both strings are the same, 1 if string1 is greater than string2.

<h4>Examples</h4>

If `mylink.myraw` contains the string "chocolate" and `mylink.mystring2` contains the string "Choccy Treat", then the following function returns the result 0.

```
ds.CompareNumNoCase(mylink.mystring1, mylink.mystring2,4)
```
{: .codeblock}
<br>

### Conversion

Converts a string to a specified internal or external storage format. The string expression evaluates the string to be converted.

The following table shows the values that you can specify for the conversion. The `conv_code` specifies types of storage formats involved in the conversion, and `conv_mode` specifies which format is used for input or output. If you specify "I" for `conv_mode`, the `ICONV()` function is used for the conversion. If you specify "O" for `conv_mode`, the `OCONV()` function is used for the conversion.

#### Table for conversion values

| `conv_code` | `conv_mode` | Description |
| -- | -- | -- |
|MX | I | Converts the input string from hexadecimal to decimal. |
|MB | I | Converts the input string from binary to decimal. |
|MX0C | I | Converts the input string from hexadecimal to ASCII character string. |
|MB0C | I | Converts the input string from binary to ASCII character string. |
|MX | O | Converts the input string from decimal to hexadecimal. |
|MB | O | Converts the input string from decimal to binary. |
|MX0C | O | Converts the input string from ASCII character string to hexadecimal. |
|MB0C | O | Converts the input string from ASCII character string to binary. |

<h4>Syntax</h4>

```
ds.Conversion(string (string), conv_code (string), conv_mode (string))
```
{: .codeblock}

returns: the converted string.

<h4>Examples</h4>

If `mylink.mystring` contains the string "1111", then the following function returns the value 15.

```
ds.Conversion(mylink.mystring,"MB", "I")
```
{: .codeblock}

If `mylink.mystring` contains the string "CDE", then the following function returns the value 434445.

```
ds.Conversion(mylink.mystring,"MX0C", "O")
```
{: .codeblock}
<br>

### Convert

Converts the characters in the string that is designated in the given expression. Converts the characters that are specified in one list to the characters specified in another list.

<h4>Syntax</h4>

```
ds.Convert(fromlist (string), tolist (string), expression (string))
```
{: .codeblock}

returns: the string with the converted designated characters.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "NOW IS THE TIME", then the following function returns the string "NOW YS XHE XYME".

```
ds.Convert("TI","XY", mylink.mystring1)
```
{: .codeblock}
<br>

### Count

Counts the number of times a substring occurs in a string.

<h4>Syntax</h4>

```
ds.Count(string (string), substring (string))
```
{: .codeblock}

returns: the number of substring occurrences in int32 format.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars", then the following function returns 3.

```
ds.Count(mylink.mystring1, "choc")
```
{: .codeblock}
<br>

### Dcount

Counts the number of delimited fields in a string.

<h4>Syntax</h4>

```
ds.Dcount(string (string), delimiter (string))
```
{: .codeblock}

returns: the number of delimited fields in int32 format.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars", then the following function returns 3.

```
ds.Dcount(mylink.mystring1,",")
```
{: .codeblock}
<br>

### DownCase

Changes all uppercase letters in a string to lowercase letters.

<h4>Syntax</h4>

```
ds.DownCase(string (string))
```
{: .codeblock}

returns: the resulting string in all lower case.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "CaMel cAsE", then the following function returns the string "camel case".

```
ds.DownCase(mylink.mystring1)
```
{: .codeblock}
<br>

### DQuote

Encloses a string in double quotation marks.

<h4>Syntax</h4>

```
ds.DQuote(string (string))
```
{: .codeblock}

returns: the resulting string enclosed in double quotation.

<h4>Examples</h4>

If `mylink.mystring1` contains the string needs quotes, then the following function returns the string "needs quotes".

```
ds.DQuote(mylink.mystring1)
```
{: .codeblock}
<br>

### Ereplace

Replaces a substring in an expression with replacement string.

If the substring argument is an empty string, the value of the replacement argument is prefixed with the value of the expression argument. If the replacement argument is an empty string, all occurrences of the substring starting from the position indicated by the value of the begin argument are removed. If the value of the occurrence argument is less than or equal to 0, all occurrences starting from the value of the begin argument are replaced. Otherwise, the number of occurrences that are replaced is indicated by the value of the occurrence argument, starting from the position indicate by the value of the begin argument. If value of the begin argument is less than or equal to 1, the replacement starts from the first occurrence. Otherwise, the replacement starts from the position indicated by the value of the begin argument.

#### Syntax

```
ds.Ereplace(expression (string), substring (string), replacement (string), [occurrence (int32), [begin (int32)]])
```
{: .codeblock}

returns: the resulting string with all occurrences of the substring replaced.

<h4>Examples</h4>

If `mylink.mystring` contains the expression "ABC" and the substring is empty, the following function returns the value "ZZZABC".

```
ds.Ereplace(mylink.mystring,"","ZZZ")
```
{: .codeblock}

If `mylink.mystring` contains the expression "aaabbbcccbbb" and the replacement is empty, the following function returns the value "aaaccc".

```
ds.Ereplace(mylink.mystring, "bbb", "")
```
{: .codeblock}
<br>

### Exchange

Replaces a character in a string.

<h4>Syntax</h4>

```
ds.Exchange(str (string), findStr (string), replaceStr (string))
```
{: .codeblock}

returns: the resulting string with replaced characters.

<h4>Examples</h4>

The following code returns: ".B.BC".

```
ds.Exchange("ABABC", "41", "2E")
```
{: .codeblock}
<br>

### EXTRACT

Access the data contents of a specified field, value, or subvalue from a dynamic array. Works similarly to REMOVE.

The input dynamic array must have only CHAR(254), CHAR(253), CHAR(252) as delimiters, and their hierachy as aforewritten. Respectively, they can be retrieved by AM or FM, VM, SM or SVM functions. FM is delimiter to the strings' fields, VM is delimiter to the strings' values, and SM is delimiter to the strings' subvalues.

To learn more about `EXTRACT`, please see [EXTRACT function](https://www.ibm.com/docs/en/iis/11.7?topic=functions-extract-function){: new_window}.

<h4>Syntax</h4>

```
ds.EXTRACT(str (string), field (int64), [value (int64), subvalue (int64)])
```
{: .codeblock}

returns: the resulting extracted string of format string.

<h4>Examples</h4>

The following code both return: "9ü3ü5". The dynamic array contains 3 fields separated by FM/AM, 2 values in the first field, 1 subvalue in the first value, and so on.

```
ds.EXTRACT("1" + ds.FM() + "4" + ds.VM() + "9" + ds.SM() + "3" + ds.SM() + "5" + ds.FM() + "1" + ds.VM() + "0" + ds.SM() + "7" + ds.SM() + "3", 2, 2)
ds.EXTRACT("1" + ds.AM() + "4" + ds.VM() + "9" + ds.SM() + "3" + ds.SM() + "5" + ds.AM() + "1" + ds.VM() + "0" + ds.SM() + "7" + ds.SM() + "3", 2, 2)
```
{: .codeblock}

The following code returns an empty string, as there are only 3 fields and not 10 or more.

```
ds.EXTRACT("1" + ds.FM() + "4" + ds.VM() + "9" + ds.SM() + "3" + ds.SM() + "5" + ds.FM() + "1" + ds.VM() + "0" + ds.SM() + "7" + ds.SM() + "3", 10, 0, 0)
```
{: .codeblock}
<br>

### Field

Returns one or more substrings that are located between specified delimiters in a string. The argument occurrence specifies which occurrence of the delimiter is to be used as a terminator. The argument number optionally specifies how many substrings to return.

<h4>Syntax</h4>

```
ds.Field(string (string), delimiter (string), occurrence (int32), [number (int32)])
```
{: .codeblock}

returns: the corresponding string between the delimiters.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars, chocolate dippers", then the following function returns the string " chocolate ice cream".

```
ds.Field(mylink.mystring1,",",2)
```
{: .codeblock}

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars, chocolate dippers", then the following function returns the string " chocolate ice cream, chocolate bars".

```
ds.Field(mylink.mystring1,",",2,2)
```
{: .codeblock}
<br>

### FieldStore

Modifies character strings by inserting, deleting, or replacing fields separated by a specified delimiters string. The delimiters string denotes the string to be modified and can be any single ASCII character. Also takes parameters `start` which is the position of the input string where modification starts, and `number` which is the number of times a new string is inserted in the input string.

<h4>Syntax</h4>

```
ds.FieldStore(str (string), delimiter (string), start (int8), number (int8), new_fields (string))
```
{: .codeblock}

returns: the modified string of format string.

<h4>Examples</h4>

The following code returns the string A#B#C#D#5:

```
ds.FieldStore("1#2#3#4#5", "#", 1, 4, "A#B#C#D")
```
{: .codeblock}
<br>

### Fmt

Uses the FMT function or a format expression to format data for output. Any BASIC expression can be formatted for output by following it with a format expression. For details on the syntax of the Fmt function, see [FMT function](https://www.ibm.com/docs/en/iis/11.7?topic=functions-fmt-function).

<h4>Syntax</h4>

```
ds.Fmt(string (string), format (string))
```
{: .codeblock}

returns: the resulting formatted data of format string.

<h4>Examples</h4>

The following code returns the string "23-69-86":

```
ds.Fmt("236986","R##-##-##")
```
{: .codeblock}

The following code returns the number "\*\*\*\*\*$555,666,898.00":

```
ds.Fmt("555666898","20*R2$,")
```
{: .codeblock}
<br>

### FmtDP

Converts a multibyte character sets of type string to the target format. If National Language Support (NLS) is not enabled, the FmtDP function works like an equivalent Fmt function. For details on the syntax of the FmtDP function, see [FmtDP function](https://www.ibm.com/docs/en/iis/11.7?topic=functions-fmt-function).

<h4>Syntax</h4>

```
ds.FmtDP(string (string), format (string), [mapname (string)])
```
{: .codeblock}

returns: the converted string of format string.

<h4>Examples</h4>

The following code returns the number 56789:

```
ds.FmtDP("123456789","R#5")
```
{: .codeblock}
<br>

### Fold

Folds strings to create substrings. string is the string to be folded. length is the length of the substrings in characters.

```
ds.Fold(str (string), length (int8))
```
{: .codeblock}

returns: the resulting folded string.

The following code returns "THISþIS AþTESTþFOLDEþD STRþING".

```
ds.Fold("THIS IS A TEST FOLDED STRING", 5)
```
{: .codeblock}
<br>

### Folddp

In National Language Support (NLS) mode, folds strings to create substrings using character display positions.

<h4>Syntax</h4>

```
ds.Folddp(str (string), length (int), opmap (string))
```
{: .codeblock}

returns: the resulting folded string.

<h4>Examples</h4>

The following code returns: "这里需要þUNICOþDE STþRING".

```
ds.Folddp("这里需要 UNICODE STRING", 5, "0")
```
{: .codeblock}
<br>

### Index

Finds the starting character position of a substring. The argument occurrence specifies which occurrence of the substring is to be located.

<h4>Syntax</h4>

```
ds.Index(string (string), substring (string), occurrence (int32))
```
{: .codeblock}

returns: the result in int32 format of number of occurrences.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars, chocolate dippers", then the following function returns the value 18.

```
ds.Index(mylink.mystring1,"chocolate",2)
```
{: .codeblock}
<br>

### Left

Returns the leftmost *n* characters of a string.

<h4>Syntax</h4>

```
ds.Left(string (string) number (int32))
```
{: .codeblock}

returns: the leftmost *n* characters of the string.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars, chocolate dippers", then the following function returns the string "chocolate".

```
ds.Left(mylink.mystring1,9)
```
{: .codeblock}
<br>

### Len

Returns the length of a string in characters.

<h4>Syntax</h4>

```
ds.Len(string (string))
```
{: .codeblock}

returns: the length of the string in int32 format.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate", then the following function returns the value 9.

```
ds.Len(mylink.mystring1)
```
{: .codeblock}
<br>

### Lendp

In National Language Support (NLS) mode, returns the length of a string with its total display positions.

<h4>Syntax</h4>

```
ds.Lendp(str (string), opmap (string))
```
{: .codeblock}

returns: the length of the string of format int64.

<h4>Examples</h4>

The following code returns: 19.

```
ds.Lendp("这里需要 UNICODE STRING", "0")
```
{: .codeblock}
<br>

### Match

Synonymous to MATCHES. Used to compare a string expression with a pattern. To learn more about `Match` syntax, please see [Match Operator](https://www.ibm.com/docs/en/iis/11.7?topic=functions-match-operator){: new_window}.

<h4>Syntax</h4>

```
ds.Match(str (string), pattern (string))
```
{: .codeblock}

returns: the result of whether the pattern matches the input string, of format boolean.

<h4>Examples</h4>

The following code returns false:

```
ds.Match("XYZ123AB", "3X3N")
```
{: .codeblock}

The following code returns true:

```
ds.Match("XYZ123AB", "3X3N...")
```
{: .codeblock}
<br>

### MatchField

Searches a string and returns the part of it that matches the input `pattern` parameter. To learn more about `MatchField` syntax, please see [MATCH Operator](https://www.ibm.com/docs/en/iis/11.7?topic=functions-match-operator){: new_window}.

<h4>Syntax</h4>

```
ds.MatchField(str (string), pattern (string), field (int))
```
{: .codeblock}

returns: the result of format string.

<h4>Examples</h4>

The following code returns the string "XYZ":

```
ds.MatchField("XYZ123AB", "3X3N...", 1)
```
{: .codeblock}
<br>

### Num

Returns 1 if the string can be converted to a number, or returns 0 otherwise.

<h4>Syntax</h4>

```
ds.Num(string (string))
```
{: .codeblock}

returns: 1 if the string can be converted to a number, or returns 0 otherwise, in int32 format.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "22", then the following function returns the value 1.

```
ds.Num(mylink.mystring1)
```
{: .codeblock}

If `mylink.mystring1` contains the string "twenty two", then the following function returns the value 0.

```
ds.Num(mylink.mystring1)
```
{: .codeblock}
<br>

### PadString

Returns the string padded with the specified number of pad characters.

<h4>Syntax</h4>

```
ds.PadString(string (string) padstring (string) padlength (int32))
```
{: .codeblock}

returns: the resulting padded string.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "AB175", then the following function returns the string "AB17500000".

```
ds.PadString(mylink.mystring1,"0",5)
```
{: .codeblock}
<br>

### REMOVE

Extracts and returns dynamic array elements that are separated by system delimiters, and to indicate which system delimiter was found. It accepts one CHAR as delimiter and returns the corresponding number as to which delimiter is found.

| Number | Delimiter Type |
| -- | -- |
| 0 | End of string |
| 1 | Item mark ASCII CHAR(255) |
| 2 | Field mark ASCII CHAR(254) |
| 3 | Value mark ASCII CHAR(253) |
| 4 | Subvalue mark ASCII CHAR(252) |
| 5 | Text mark ASCII CHAR(251) |
| 6 | ASCII CHAR(250) (Not available in the PIOPEN flavor) |
| 7 | ASCII CHAR(249) (Not available in the PIOPEN flavor) |
| 8 | ASCII CHAR(248) (Not available in the PIOPEN flavor) |

For more information on the REMOVE function, see [REMOVE function](https://www.ibm.com/docs/en/iis/11.7?topic=functions-remove-function){: new_window}.

<h4>Syntax</h4>

```
ds.REMOVE(str (string))
```
{: .codeblock}

returns: the resulting string with delimiters removed of format string list, and the number that corresponds to the delimiter found.

<h4>Examples</h4>

The following code returns ["3","12"].

```
ds.REMOVE("12" + ds.VM() + "12" + ds.VM())
```
{: .codeblock}
<br>

### Right

Returns the rightmost *n* characters of a string.

<h4>Syntax</h4>

```
ds.Right(string (string) number (int32))
```
{: .codeblock}

returns: the rightmost *n* characters of a string.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "chocolate drops, chocolate ice cream, chocolate bars, chocolate dippers", then the following function returns the string "dippers".

```
ds.Right(mylink.mystring1,7)
```
{: .codeblock}
<br>

### Soundex

Returns a code that identifies a set of words that are (roughly) phonetically alike based on the standard, open algorithm for SOUNDEX evaluation.

<h4>Syntax</h4>

```
ds.Soundex(string (string))
```
{: .codeblock}

returns: the code that identifies a set of phonetically alike words.

<h4>Examples</h4>

If `mylink.mystring1` contains the string "Griffin", then the following function returns the code "G615".

```
ds.Soundex(mylink.mystring1)
```
{: .codeblock}

If `mylink.mystring1` contains the string "Griphin" then the following function also returns the code "G615".

```
ds.Soundex(mylink.mystring1)
```
{: .codeblock}
<br>

### Space

Returns a string of *n* space characters.

<h4>Syntax</h4>

```
ds.Space(length (int32))
```
{: .codeblock}

returns: a string of white spaces with specified length.

<h4>Examples</h4>

If `mylink.mylength` contains the number 100, then the following function returns a string that contains 100 space characters.

```
ds.Space(mylink.mylength)
```
{: .codeblock}
<br>

### SQuote

Encloses a string in single quotation marks.

<h4>Syntax</h4>

```
ds.SQuote(string (string))
```
{: .codeblock}

returns: the string enclosed in single quotation marks.

<h4>Examples</h4>

If `mylink.mystring1` contains the string needs quotes, then the following function returns the string 'needs quotes'.

```
ds.SQuote(mylink.mystring1)
```
{: .codeblock}
<br>

### Str

Repeats a string the specified number of times.

<h4>Syntax</h4>

```
ds.Str(string (string), repeats (int32))
```
{: .codeblock}

returns: the resulting string repeated *n* times.

<h4>Examples</h4>

If `mylink.mystring1` contains the string needs "choc", then the following function returns the string "chocchocchocchocchoc".

```
ds.Str(mylink.mystring1,5)
```
{: .codeblock}
<br>

### StripWhiteSpace

Returns the string after removing all white space characters from it.

<h4>Syntax</h4>

```
ds.StripWhiteSpace(string (string))
```
{: .codeblock}

returns: the string without white spaces.

<h4>Examples</h4>

If `mylink.mystring` contains the string "too   many    spaces", then the following function returns the string "toomanyspaces":

```
ds.StripWhiteSpace(mylink.mystring)
```
{: .codeblock}
<br>

### Substring

Returns the specified substring.

When *n* is specified, function gets the last *n* characters of a string.

When *start* and *length* is specified, function gets the characters with length equal to *length* starting from the *start* position of a string.

When *delimiter* is specified, function gets one or more substrings located between specified delimiters in a string. *occu* is the number of delimiters and *num* is the length of the substring between delimiters in the resulting substring.

<h4>Syntax</h4>

```
ds.Substring(string (string), n (int8))
ds.Substring(string (string), start (int8), length (int8))
ds.Substring(string (string), delimiter (string), occu (int8), num (int8))
```
{: .codeblock}

returns: the resulting substring array of format string.

<h4>Examples</h4>

The following code returns "ab.cd".

```
ds.Substring("ab.cd", ".", 1, 2)
```
{: .codeblock}
<br>

### Substrings

Creates a dynamic array, of which all elements are substrings of the corresponding elements of the input dynamic array.

<h4>Syntax</h4>

```
ds.Substrings(str (string), start (int8), length (int8))
```
{: .codeblock}

returns: the resulting dynamic array with substrings corresponding to the input array, of string format.

<h4>Examples</h4>

The following code returns "NESýITHþ23üý50ü".

```
ds.Substrings("JONESýSMITHþ1.23ü20ý2.50ü10", 3, 20)
```
{: .codeblock}
<br>

### Trim

Removes all leading and trailing spaces and tabs. The function also reduces the internal occurrences of spaces or tabs to one.

The argument *stripchar* optionally specifies a character other than a space or a tab. The argument *options* optionally specifies the type of trim operation to be performed and contains one or more of the following values:

- **A**: Remove all occurrences of *stripchar*.

- **B** Remove both leading and trailing occurrences of *stripchar*.

- **D** Remove leading, trailing, and redundant white-space characters.

- **E** Remove trailing white-space characters.

- **F** Remove leading white-space characters.

- **L** Remove all leading occurrences of *stripchar*.

- **R** Remove leading, trailing, and redundant occurrences of *stripchar*.

- **T** Remove all trailing occurrences of *stripchar*.

<h4>Syntax</h4>

```
ds.Trim(string (string), [stripchar (string)], [options (string)])
```
{: .codeblock}

returns: the trimmed string.

<h4>Examples</h4>

If `mylink.mystring` contains the string " String with whitespace ", then the following function returns the string "String with whitespace":

```
ds.Trim(mylink.mystring)
```
{: .codeblock}

If `mylink.mystring` contains the string "..Remove..redundant..dots....", then the following function returns the string "Remove.redundant.dots":

```
ds.Trim(mylink.mystring,".")
```
{: .codeblock}

If `mylink.mystring` contains the string "Remove..all..dots....", then the following function returns the string "Removealldots":

```
ds.Trim(mylink.mystring,".","A")
```
{: .codeblock}

If `mylink.mystring` contains the string "Remove..trailing..dots....", then the following function returns the string "Remove..trailing..dots":

```
ds.Trim(mylink.mystring,".","T")
```
{: .codeblock}
<br>

### TrimB

Removes all trailing spaces and tabs from a string.

<h4>Syntax</h4>

```
ds.TrimB(string (string))
```
{: .codeblock}

returns: the trimmed string.

<h4>Examples</h4>

If `mylink.mystring` contains the string "too many trailing spaces    ", then the following function returns the string "too many trailing spaces":

```
ds.TrimB(mylink.mystring)
```
{: .codeblock}
<br>

### TrimF

Removes all leading spaces and tabs from a string.

<h4>Syntax</h4>

```
ds.TrimF(string (string))
```
{: .codeblock}

returns: the trimmed string.

<h4>Examples</h4>

If `mylink.mystring` contains the string "    too many leading spaces", then the following function returns the string "too many leading spaces":

```
ds.TrimF(mylink.mystring)
```
{: .codeblock}
<br>

### TrimLeadingTrailing

Removes all leading and trailing spaces and tabs from a string.

<h4>Syntax</h4>

```
ds.TrimLeadingTrailing(string (string))
```
{: .codeblock}

returns: the trimmed string.

<h4>Examples</h4>

If `mylink.mystring` contains the string " too many spaces ", then the following function returns the string "too many spaces":

```
ds.TrimLeadingTrailing(mylink.mystring)
```
{: .codeblock}
<br>

### UpCase

Changes all lowercase letters in a string to uppercase.

#### Syntax

```
ds.UpCase(string (string))
```
{: .codeblock}

returns: the resulting string in all upper case.

#### Examples

If `mylink.mystring1` contains the string "CaMel cAsE", then the following function returns the string "CAMEL CASE":

```
ds.UpCase(mylink.mystring1)
```
{: .codeblock}

### IM

Returns CHAR(255). Works the same as AM.

#### Syntax

```
ds.IM()
```
{: .codeblock}

returns: the resulting CHAR(255).

#### Examples

The following code returns 'ÿ'.

```
ds.IM()
```
{: .codeblock}
<br>

### FM

Returns CHAR(254).

#### Syntax

```
ds.FM()
```
{: .codeblock}

returns: the resulting CHAR(254).

#### Examples

The following code returns 'þ'.

```
ds.FM()
```
{: .codeblock}
<br>

### AM

Returns CHAR(254). Works the same as FM.

#### Syntax

```
ds.AM()
```
{: .codeblock}

returns: the resulting CHAR(254).

#### Examples

The following code returns 'þ'.

```
ds.AM()
```
{: .codeblock}
<br>

### VM

Returns CHAR(253).

#### Syntax

```
ds.VM()
```
{: .codeblock}

returns: the resulting CHAR(253).

#### Examples

The following code returns 'ý'.

```
ds.VM()
```
{: .codeblock}
<br>

### SM

Returns CHAR(252). Works the same as SVM.

#### Syntax

```
ds.SM()
```
{: .codeblock}

returns: the resulting CHAR(252).

#### Examples

The following code returns 'ü'.

```
ds.SM()
```
{: .codeblock}
<br>

### SVM

Returns CHAR(252). Works the same as SM.

#### Syntax

```
ds.SVM()
```
{: .codeblock}

returns: the resulting CHAR(252).

#### Examples

The following code returns 'ü'.

```
ds.SVM()
```
{: .codeblock}
<br>

### TM

Returns CHAR(251).

#### Syntax

```
ds.TM()
```
{: .codeblock}

returns: the resulting CHAR(251).

#### Examples

The following code returns 'û'.

```
ds.TM()
```
{: .codeblock}
<br>
<!--End of string functions-->

## Utility functions
{: #utility}

The utility functions specifies a variety of purposes related to retrieving information about specific {{ site.data.keyword.datastage }} functions.

### ElementAt

Returns the element in the list specified by the index.

<h4>Syntax</h4>

```
ds.ElementAt(list (object))
```
{: .codeblock}

returns: the element index of format object.

<h4>Examples</h4>

The following code returns 'b':

```
ds.ElementAt(["a","b","c"], 1)
```
{: .codeblock}

The following code returns 2:

```
ds.ElementAt([1,2,3], 1)
```
{: .codeblock}
<br>

### GetCommandName

Takes the node ID of a "Run Bash Script activity" and the retrieves the command name of the Run bash script activity.

<h4>Syntax</h4>

```
ds.GetCommandName(tasks.activity_id (string))
```
{: .codeblock}

returns: the command name of format string.

<h4>Examples</h4>

The following code returns the command name of task `run_bash_script_5`:

```
ds.GetCommandName(tasks.run_bash_script_5)
```
{: .codeblock}
<br>

### GetCommandOutput

Takes the node ID of a "Run Bash Script activity" and retrieves its standard output. It is equivalent to the CEL expression:

```
tasks.<activity_id>.results.standard_output
```
{: .codeblock}

<h4>Syntax</h4>

```
ds.GetCommandOutput(tasks.activity_id (string))
```
{: .codeblock}

returns: the standard output of format string.

<h4>Examples</h4>

The following code returns the standard output of task `run_bash_script_5`:

```
ds.GetCommandOutput(tasks.run_bash_script_5)
```
{: .codeblock}
<br>

{% comment %}
<!--https://github.ibm.com/DataStage/datastage-cel-ext/commit/5e4d9c991b5e89b92d40860f375a2c3d9db9c1c5#diff-a48d328dc7dcc8312a8ef361171416fcb58344d99e51c0ee193dcc6d24cf6b29-->
### GetEnvironment

Returns the value of the given environment variable.

<h4>Syntax</h4>

```
ds.GetEnvironment(environment variable (string))
```
{: .codeblock}

returns: the value of the environment variable in string format.

<h4>Examples</h4>
<!--Does this apply for {{site.data.keyword.pipeline_full}}?-->
If you queried the value of the environment variable name `APT_RDBMS_COMMIT_ROWS` then the following derivation might return the value "2048":

```
ds.GetEnvironment("APT_RDBMS_COMMIT_ROWS")
```
{: .codeblock}
<br>
{% endcomment %}

### GetErrorMessage

Used in the task in an exception handler only, the output is the text of the message that will be logged as a warning when the exception is raised.

<h4>Syntax</h4>

```
ds.GetErrorMessage()
```
{: .codeblock}

returns: the resulting message of format string.

<h4>Examples</h4>

The following code returns the error message of a failed task:

```
ds.GetErrorMessage()
```
{: .codeblock}

<br>

### GetErrorNumber

Used in the task in an exception handler only, the output is the integer which indicates the type of error that is invoked. Either 1 or -1.

1 indicates that the task ran a job that aborted, and there was no specific handler set up.

-1 indicates that the task failed to run for other reasons.

<h4>Syntax</h4>

```
ds.GetErrorNumber()
```
{: .codeblock}

returns: the resulting integer of format int.

<h4>Examples</h4>

The following code returns the error number of the type of Exception Handler activity:

```
ds.GetErrorNumber()
```
{: .codeblock}

<br>

### GetErrorSource

Used in the task in an exception handler only, the output is the stage name of the activity stage that raised the exception.

<h4>Syntax</h4>

```
ds.GetErrorSource()
```
{: .codeblock}

returns: the resulting value of the task of format string.

<h4>Examples</h4>

The following code returns the task that failed:

```
ds.GetErrorSource()
```
{: .codeblock}

<br>

### GetJobName

Returns the job name of the Run {{ site.data.keyword.datastage }} activity at the time the function is executed. It is equivalent to the CEL expression:

```
tasks.<activity_id>.results.job_name
```
{: .codeblock}

<h4>Syntax</h4>

```
ds.GetJobName(tasks.activity_id (string))
```
{: .codeblock}

returns: the job name of format string.

<h4>Examples</h4>

The following code returns the job name of task `run_datastage_flow_1`:

```
ds.GetJobName(tasks.run_datastage_flow_1)
```
{: .codeblock}
<br>

### GetJobStatus

Takes the node ID of a "Run {{ site.data.keyword.datastage }} activity" and retrieves its job status for `<activity_name>.$JobStatus`. It is equivalent to the following cel expression:

```
((tasks.<activity_id>.results.status == 'Completed') ? 1 : ((tasks.<activity_id>.results.status == 'CompletedWithWarnings') ? 2 : ((tasks.<activity_id>.results.status == 'Cancelled') ? 96 : 3)))
```
{: .codeblock}

<h4>Syntax</h4>

```
ds.GetJobStatus(tasks.activity_id (string))
```
{: .codeblock}

returns: the job status of format int.

<h4>Examples</h4>

The following code returns the status of task `run_datastage_flow_1`:

```
ds.GetJobStatus(tasks.run_datastage_flow_1)
```
{: .codeblock}
<br>

### GetListCounter

Used in the task in a loop with a list counter only, the output is the current value of the counter variable.

<h4>Syntax</h4>

```
ds.GetListCounter()
```
{: .codeblock}

returns: the resulting value of the counter of format string.

<h4>Examples</h4>

The following code returns the current value of the loop.

```
ds.GetListCounter()
```
{: .codeblock}

<br>

### GetNumericCounter

Used in the task in a loop with a numeric counter only, the output is the current value of the counter variable of the loop.

<h4>Syntax</h4>

```
ds.GetNumericCounter()
```
{: .codeblock}

returns: the resulting value of the counter of format int.

<h4>Examples</h4>

The following code returns the current value of the loop.

```
ds.GetNumericCounter()
```
{: .codeblock}

<br>

### GetReturnValue

Takes the node ID of a "Run Bash Script activity" and returns the value of the Run Bash Script activity. It is equivalent to the following CEL expression:

```
tasks.<activity_id>.results.return_value
```
{: .codeblock}

<h4>Syntax</h4>

```
ds.GetReturnValue(tasks.activity_id (string))
```
{: .codeblock}

returns: the resulting value of the task of format int.

<h4>Examples</h4>

The following code returns the value of task `tasks.run_bash_script_5`:

```
ds.GetReturnValue(tasks.run_bash_script_5)
```
{: .codeblock}

<br>

### GetUserStatus

Takes the ID of a {{ site.data.keyword.datastage }} flow task and returns the status of the {{ site.data.keyword.datastage }} flow task in the sequence job. Does not work if run in parallel job. It is equivalent to the CEL expression:

```
tasks.<activity_id>.results.user_status
```
{: .codeblock}

<h4>Syntax</h4>

```
ds.GetUserStatus(tasks.run_datastage_id (string))
```
{: .codeblock}

returns: the status of the {{ site.data.keyword.datastage }} flow task id of format string.

<h4>Examples</h4>

The following code returns the value of task id `run_datastage_5`:

```
ds.GetUserStatus(tasks.run_datastage_5)
```
{: .codeblock}

<br>

{% comment %}
### GetSavedInputRecord
<!--Does this apply for {{site.data.keyword.pipeline_full}}?-->
This function is used to implement the aggregating of data. You call the `GetsSavedInputRecord` function to retrieve an input that you have previously saved to a cache area. The function retrieves the next input row from the cache (in the order in which they were saved to the cache) and makes it the current input row. The retrieved row overrides what was the current input row, and so any derivation using an input column value will use the value of that column in the input row retrieved from the cache, not what was previously the current input row. You must call GetSavedInputRecord in a loop variable derivation, you cannot call it from anywhere else. For example, you cannot call GetSavedInputRecord in the Loop Condition expression. You can call GetSavedInputRecord, multiple times and retrieve the next cached row on each call. Use the SaveInputRecord function to store rows to the cache. GetSavedInputRecord returns the cache index number of the record retrieved from that cache.

<h4>Syntax</h4>

```
ds.GetSavedInputRecord()
```
{: .codeblock}

returns: the value of the `cache_index_number` of format `cache_index_number`.

<h4>Examples</h4>

The following example is the derivation of a loop variable named SavedRecordIndex in a Transformer stage:

```
ds.SavedRecordIndex: GetSavedInputRecord()
```
{: .codeblock}
<br>
{% endcomment %}

### LogName

Returns the login name of the current user.

<h4>Syntax</h4>

```
ds.LogName()
```
{: .codeblock}

returns: the login name of the current user of format string.

<h4>Examples</h4>

The following code returns the login name of the current user.

```
ds.LogName()
```
{: .codeblock}

<br>

### Path

Returns the path name of the current user.

<h4>Syntax</h4>

```
ds.Path()
```
{: .codeblock}

returns: the path name of the current user of format string.

<h4>Examples</h4>

The following code returns the path name of the current user.

```
ds.Path()
```
{: .codeblock}

<br>

{% comment %}
### SaveInputRecord

This function is used to implement the aggregating of data on the input. Call the `SaveInputRecord` function to save a copy of the current input row to a cache area. The function returns the count of records in the cache, starting from 1. You can call `SaveInputRecord` multiple times for the same input row. The first call adds the input row to the cache and each subsequent call adds a duplicate of that same input row into the cache. For example, if `SaveInputRecord` is called three times for one input record, then the cache will contain three rows, each identical to the original input row. Use the `GetSavedInputRecord` function to retrieve the rows that you have stored.

<h4>Syntax</h4>

```
ds.SaveInputRecord()
```
{: .codeblock}

returns: the cache record count of format int64.

<h4>Examples</h4>

The following example is the derivation of a stage variable named `NumSavedRecords`:

```
ds.NumSavedRecords: SaveInputRecord()
```
{: .codeblock}

<br>
{% endcomment %}

### Schema

Returns the schema name of the current user.

<h4>Syntax</h4>

```
ds.Schema()
```
{: .codeblock}

returns: the schema name of the current user of format string.

<h4>Examples</h4>

The following code returns the schema name of the current user.

```
ds.Schema()
```
{: .codeblock}

<br>

### UserNo

Returns the user number of the current user.

<h4>Syntax</h4>

```
ds.UserNo()
```
{: .codeblock}

returns: the user information of the current user of format int.

<h4>Examples</h4>

The following code returns the user number of the current user.

```
ds.UserNo()
```
{: .codeblock}

<br>

### Who

Returns the current user.

<h4>Syntax</h4>

```
ds.Who()
```
{: .codeblock}

returns: the current user of format string.

<h4>Examples</h4>

The following code returns the current user.

```
ds.Who()
```
{: .codeblock}

<br>
<!--End of utility functions-->

## Null functions
{: #null}

Functions that do null handling.

### IsNull

Returns true when the input expression evaluates to the null value.

<h4>Syntax</h4>

```
ds.IsNull(input (any))
```
{: .codeblock}

returns: the result of whether the expression evaluates to null, of format boolean.

<h4>Examples</h4>

The following code returns true.

```
ds.IsNull(null)
```
{: .codeblock}

The following code returns false.

```
ds.IsNull(0)
```
{: .codeblock}
<br>

### IsNotNull

Returns true when the input expression does not evaluate to the null value.

<h4>Syntax</h4>

```
ds.IsNotNull(input (any))
```
{: .codeblock}

returns: the result of whether the expression does not evaluate to null, of format boolean.

<h4>Examples</h4>

The following code returns false.

```
ds.IsNotNull(null)
```
{: .codeblock}

The following code returns true.

```
ds.IsNotNull(0)
```
{: .codeblock}

<br>

### Null

Returns the null value.

<h4>Syntax</h4>

```
ds.Null()
```
{: .codeblock}

returns: the null value.

<h4>Examples</h4>

The following code returns null.

```
ds.Null()
```
{: .codeblock}

<br>

### NullToEmpty

Returns an empty string if the input is null, otherwise returns the input column value.

<h4>Syntax</h4>

```
ds.NullToEmpty(input (any))
```
{: .codeblock}

returns: an empty string or the input value.

<h4>Examples</h4>

The following code returns "AA".

```
ds.NullToEmpty("AA")
```
{: .codeblock}

The following code returns "".

```
ds.NullToEmpty(null)
```
{: .codeblock}

<br>

### NullStr

Returns the null string CHAR(128).

<h4>Syntax</h4>

```
ds.NullStr()
```
{: .codeblock}

returns: the null string CHAR(128).

<h4>Examples</h4>

The following code returns €.

```
ds.NullStr()
```
{: .codeblock}

<br>

### NullToValue

Returns the specified value if the input is null, otherwise returns the input column value.

<h4>Syntax</h4>

```
ds.NullToValue(input (any), default (any))
```
{: .codeblock}

returns: the specified value or the input value.

<h4>Examples</h4>

The following code returns "test".

```
ds.NullToValue("test", "default")
```
{: .codeblock}

The following code returns "default".

```
ds.NullToValue(null, "default")
```
{: .codeblock}

The following code returns 1.

```
ds.NullToValue(null, 1)
```
{: .codeblock}

<br>

### NullToZero

Returns 0 if the input is null, otherwise returns the input column value.

<h4>Syntax</h4>

```
ds.NullToZero(input (any))
```
{: .codeblock}

returns: 0 or the input value.

<h4>Examples</h4>

The following code returns 88.

```
ds.NullToZero(88)
```
{: .codeblock}

The following code returns 0.

```
ds.NullToZero(null)
```
{: .codeblock}

<br>

### SetNull

Assigns a null value to the target column.

<h4>Syntax</h4>

```
ds.SetNull()
```
{: .codeblock}

returns: sets the target to the null value.

<h4>Examples</h4>

The following code returns null.

```
ds.SetNull()
```
{: .codeblock}
<br>
<!--End of null functions-->

## Macros functions
{: #macros_1}

Functions that handle retrieval of a set of project metadata related to {{ site.data.keyword.datastage }} sequence jobs.

### JobName

Returns the sequencer job name.

<h4>Syntax</h4>

```
ds.JobName
```
{: .codeblock}

returns: the sequencer job name of format string.

<h4>Examples</h4>

The following code returns the sequencer job name.

```
ds.JobName
```
{: .codeblock}

<br>

### JobStartDate

Returns the sequencer job start date.

<h4>Syntax</h4>

```
ds.JobStartDate
```
{: .codeblock}

returns: the sequencer job start date of format string.

<h4>Examples</h4>

The following code returns the sequencer job start date.

```
ds.JobStartDate
```
{: .codeblock}

<br>

### JobStartTime

Returns the sequencer job start time.

<h4>Syntax</h4>

```
ds.JobStartTime
```
{: .codeblock}

returns: the sequencer job start time of format string.

<h4>Examples</h4>

The following code returns the sequencer job start time.

```
ds.JobStartTime
```
{: .codeblock}

<br>

### JobStartTimestamp

Returns the sequencer job start timestamp.

<h4>Syntax</h4>

```
ds.JobStartTimestamp
```
{: .codeblock}

returns: the sequencer job start timestamp of format timestamp.

<h4>Examples</h4>

The following code returns the sequencer job start timestamp.

```
ds.JobStartTimestamp
```
{: .codeblock}

<br>

### HostName

Returns the host name of {{site.data.keyword.datastage}} server.

<h4>Syntax</h4>

```
ds.HostName
```
{: .codeblock}

returns: the sequencer job `InvocationId` of format string.

<h4>Examples</h4>

The following code returns the sequencer job `InvocationId`.

```
ds.HostName
```
{: .codeblock}

<br>

### ProjectName

Returns the project name of the running sequencer job

<h4>Syntax</h4>

```
ds.ProjectName
```
{: .codeblock}

returns: the project name of the running sequencer job.

<h4>Examples</h4>

The following code returns the project name of the running sequencer job.

```
ds.ProjectName
```
{: .codeblock}

<br>

### ProjectId

Returns the project ID of the running sequencer job.

<h4>Syntax</h4>

```
ds.ProjectId
```
{: .codeblock}

returns: the project ID of the running sequencer job.

<h4>Examples</h4>

The following code returns the project ID of the running sequencer job.

```
ds.ProjectId
```
{: .codeblock}

<br>

### JobId

Returns the job ID of the running sequencer job.

<h4>Syntax</h4>

```
ds.JobId
```
{: .codeblock}

returns: the job ID of the running sequencer job.

<h4>Examples</h4>

The following commands returns the job ID of the running sequencer job.

```
ds.JobId
```
{: .codeblock}
<br>

### JobController
{%- if site.prodkey == "icpd" %}
<button class="bx--tag bx--tag--blue"><span class="bx--tag__label">4.6.3 and later</span></button>
<br><br>
{% endif %}

Returns the job run ID of the running sequencer job.

<h4>Syntax</h4>

```
ds.JobController
```
{: .codeblock}

returns: the job run ID of the running sequencer job.

<h4>Examples</h4>

The following commands returns the job run ID of the running sequencer job.

```
ds.JobController
```
{: .codeblock}

<br>

**Parent topic:** [Adding conditions to a pipeline](ml-orchestration-conditions.html)

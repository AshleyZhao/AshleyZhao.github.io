created: "2021-07-09 09:02:55 -0400"
title: "Coding elements for pipelines"
---
{{site.data.keyword.attributedefs}}

# Functions used in {{ site.data.keyword.pipeline_short }}'s Expression Builder

Use these functions in {{ site.data.keyword.pipeline }} code editors, for example, to define a user variable or build an advanced condition.
{: .shortdesc}

To see {{ site.data.keyword.pipeline }} functions transferred from {{ site.data.keyword.datastage }}, see [DataStage Functions used in pipelines Expression Builder](ml-orchestration-expr-builder-ds.html).

{% if site.prodkey=="cloud" %}
**Note:** This tool is provided as a beta release and is not supported for use in production environments.
{% endif %}

{% if site.prodkey=="icpd" %}
**Note:** In the current version of {{site.data.keyword.pipeline}}, all input types of date, time, and timestamp are treated as strings.
{% endif %}

The Experssion Builder uses these catagories for coding functions:
<!--Reminder: Get DS functions into separate topic-->
- [Conversion functions](#conversion)
- [Standard functions](#ofext)

## Conversion functions
{: #conversion}

Converts a single data element format to another.
<br>

### Table for basic data type conversion

| Type | Accepts | Returns | Syntax |
| -- | -- | -- | -- |
|`double` | `int, uint, string` | `double` | `double(val)`
|`duration` | `string` | `duration` | `duration(string)` <br> Duration should end with "s", which stands for seconds.
|`int` | `int, uint, double, string, timestamp` | `int` | `int(val)`
|`timestamp` | `string` | `timestamp` | `timestamp(string)` <br> Converts strings to timestamps according to RFC3339, i.e. "1972-01-01T10:00:20.021-05:00".
|`uint` | `int, double, string` | `uint` | `uint(val)` |

<h4>Example</h4>

For example, to cast a value to type `double`:

```
double(%val%)
```
{: .codeblock}

This applies to all casting functions listed in the previous table. When casting double to `int | uint`, result rounds toward zero and errors if result is out of range.
<br>

## Standard functions
{: #ofext}

Functions that are unique to {{site.data.keyword.pipeline_full}}.
<!--Combined section-->
<!--Issues in Orchestrator_ext, Standard_ext, Language_def-->
<!--2. Issue: format function -- 2 functions in the JSON docs, one takes param 1, param 2, param 3...other takes layout. One is a method of TimeStamp. A: Different "methodOf"-->
<!--3. what is the difference between "now" and "currentTimestamp"? It seems like the Date and Time functions return something called "translationsHelper.msg.XXX_output". What does that do? A: Output type slightly different-->
<!--5. What is translationsHelper.msg.XXX_output as a return function? Does it have something to do with them added as columns? A: Can just ignore-->
<br>

### sub

Replaces substrings of a string that matches the given regular expression starting at position offset.

<h4>Syntax</h4>

```
(string).sub(substring (string), replacement (string), [occurrence (int), [offset (int)]])
```
{: .codeblock}

returns: the string with substrings updated.

<h4>Examples</h4>

```
'aaabbbcccbbb'.sub('[b]+','RE')
```
{: .codeblock}

Returns 'aaaREcccRE'.
<br>

### format

Formats a string or timestamp according to a format specifier and returns the resulting string.

<h4>Syntax</h4>

**_format_ as a method of strings**

```
(string).format(parameter 1 (string or bool or number)... parameter 10 (string or bool or number))
```
{: .codeblock}

returns: the string containing the formatted input values.

**_format_ as a method of timestamps**

```
(timestamp).format(layout(string))
```
{: .codeblock}

returns: the formatted timestamp in string format.

<h4>Examples</h4>

```
'number=%d, text=%s'.format(1, 'str')
```
{: .codeblock}

Returns the string 'number=1, text=str'.

```
timestamp('2020-07-24T09:07:29.000-00:00').format('%Y/%m/%d')
```
{: .codeblock}

Returns the string '2020/07/24'.
<br>

### now

Returns the current timestamp.

<h4>Syntax</h4>

```
now()
```
{: .codeblock}

returns: the current timestamp.

<!--#### Examples-->
<br>

### parseTimestamp

Returns the current timestamp in string format.

<h4>Syntax</h4>

```
parseTimestamp([timestamp_string(string)] [layout(string)])
```
{: .codeblock}

returns: the current timestamp to a string of type string.

<h4>Examples</h4>

```
parseTimestamp('2020-07-24T09:07:29Z')
```
{: .codeblock}

Returns '2020-07-24T09:07:29.000-00:00'.
<br>

### min

Returns minimum value in list.

<h4>Syntax</h4>

```
(list).min()
```
{: .codeblock}

returns: the minimum value of the list.

<h4>Examples</h4>

```
[1,2,3].min()
```
{: .codeblock}

Returns the integer 1.
<br>

### max

Returns maximum value in list.

<h4>Syntax</h4>

```
(list).max()
```
{: .codeblock}

returns: the maximum value of the list.

<h4>Examples</h4>

```
[1,2,3].max()
```
{: .codeblock}

Returns the integer 3.
<br>

### argmin

Returns index of minimum value in list.

<h4>Syntax</h4>

```
(list).argmin()
```
{: .codeblock}

returns: the index of the minimum value of the list.

<h4>Examples</h4>

```
[1,2,3].argmin()
```
{: .codeblock}

Returns the integer 0.
<br>

### argmax

Returns index of maximum value in list.

<h4>Syntax</h4>

```
(list).argmax()
```
{: .codeblock}

returns: the index of the maximum value of the list.

<h4>Examples</h4>

```
[1,2,3].argmax()
```
{: .codeblock}

Returns the integer 2.
<br>

### sum

Returns sum of values in list.

<h4>Syntax</h4>

```
(list).sum()
```
{: .codeblock}

returns: the index of the maximum value of the list.

<h4>Examples</h4>

```
[1,2,3].argmax()
```
{: .codeblock}

Returns the integer 2.
<br>

### base64.decode

Decodes base64-encoded string to bytes. This function will return an error if the string input is not base64-encoded.

<h4>Syntax</h4>

```
base64.decode(base64_encoded_string(string))
```
{: .codeblock}

returns: the decoded base64-encoded string in byte format.

<h4>Examples</h4>

```
base64.decode('aGVsbG8=')
```
{: .codeblock}

Returns 'hello' in bytes.
<br>

### base64.encode

Encodes bytes to a base64-encoded string.

<h4>Syntax</h4>

```
base64.encode(bytes_to_encode (bytes))
```
{: .codeblock}

returns: the encoded base64-encoded string of the original byte value.

<h4>Examples</h4>

```
base64.decode(b'hello')
```
{: .codeblock}

Returns 'aGVsbG8=' in bytes.
<br>

### charAt

Returns the character at the given position. If the position is negative, or greater than the length of the string, the function will produce an error.

<h4>Syntax</h4>

```
(string).charAt(index (int))
```
{: .codeblock}

returns: the character of the specified position in integer format.

<h4>Examples</h4>

```
'hello'.charAt(4)
```
{: .codeblock}

Returns the character 'o'.
<br>

### indexOf

Returns the integer index of the first occurrence of the search string. If the search string is not found the function returns -1.

<h4>Syntax</h4>

```
(string).indexOf(search_string (string), [offset (int)])
```
{: .codeblock}

returns: the index of the first character occurrence after the offset.

<h4>Examples</h4>

```
'hello mellow'.indexOf('ello', 2)
```
{: .codeblock}

Returns the integer 7.
<br>

### lowerAscii

Returns a new string with ASCII characters turned to lower-case.

<h4>Syntax</h4>

```
(string).lowerAscii()
```
{: .codeblock}

returns: the new lower case string.

<h4>Examples</h4>

```
'TacoCat'.lowerAscii()
```
{: .codeblock}

Returns the string 'tacocat'.
<br>

### replace

Returns a new string based on the target, which replaces the occurrences of a search string with a replacement string if present. The function accepts an optional limit on the number of substring replacements to be made.

<h4>Syntax</h4>

```
(string).replace(search_string (string), replacement (string), [offset (int)])
```
{: .codeblock}

returns: the new string with occurrences of a search string replaced.

<h4>Examples</h4>

```
'hello hello'.replace('he', 'we')
```
{: .codeblock}

Returns the string 'wello wello'.
<br>

### split

Returns a list of strings split from the input by the given separator. The function accepts an optional argument specifying a limit on the number of substrings produced by the split.

<h4>Syntax</h4>

```
(string).split(separator (string), [limit (int)])
```
{: .codeblock}

returns: the split string as a string list.

<h4>Examples</h4>

```
'hello hello hello'.split(' ')
```
{: .codeblock}

Returns the string list ['hello', 'hello', 'hello'].
<br>

### substring

Returns the substring given a numeric range corresponding to character positions. Optionally may omit the trailing range for a substring from a given character position until the end of a string.

<h4>Syntax</h4>

```
(string).substring(start (int), [end (int)])
```
{: .codeblock}

returns: the substring at the specified index of the string.

<h4>Examples</h4>

```
'tacocat'.substring(4)
```
{: .codeblock}

Returns the string 'cat'.
<br>

### trim

Returns a new string which removes the leading and trailing whitespace in the target string. The trim function uses the Unicode definition of whitespace which does not include the zero-width spaces.

<h4>Syntax</h4>

```
(string).trim()
```
{: .codeblock}

returns: the new string with whitespaces removed.

<h4>Examples</h4>

```
'  \ttrim\n    '.trim()
```
{: .codeblock}

Returns the string 'trim'.
<br>

### upperAscii

Returns a new string where all ASCII characters are upper-cased.

<h4>Syntax</h4>

```
(string).upperAscii()
```
{: .codeblock}

returns: the new string with all characters turned to uppercase.

<h4>Examples</h4>

```
'TacoCat'.upperAscii()
```
{: .codeblock}

Returns the string 'TACOCAT'.
<br>

### size

Returns length of the string, bytes, list, or map.

<h4>Syntax</h4>

```
(string | bytes | list | map).size()
```
{: .codeblock}

returns: the length of the string, bytes, list, or map array.

<h4>Examples</h4>

```
'hello'.size()
```
{: .codeblock}

Returns the integer 5.

```
b'hello'.size()
```
{: .codeblock}

Returns the integer 5.

```
['a','b','c'].size()
```
{: .codeblock}

Returns the integer 3.

```
{'key': 'value'}.size()
```
{: .codeblock}

Returns the integer 1.
<br>

### contains

Tests whether the string operand contains the substring.

<h4>Syntax</h4>

```
(string).contains(substring (string))
```
{: .codeblock}

returns: a boolean value of whether the substring exists in the string operand.

<h4>Examples</h4>

```
'hello'.contains('ll')
```
{: .codeblock}

Returns true.
<br>

### endsWith

Tests whether the string operand ends with the specified suffix.

<h4>Syntax</h4>

```
(string).endsWith(suffix (string))
```
{: .codeblock}

returns: a boolean value of whether the string ends with specified suffix in the string operand.

<h4>Examples</h4>

```
'hello'.endsWith('llo')
```
{: .codeblock}

Returns true.
<br>

### startsWith

Tests whether the string operand starts with the prefix argument.

<h4>Syntax</h4>

```
(string).startsWith(prefix (string))
```
{: .codeblock}

returns: a boolean value of whether the string begins with specified prefix in the string operand.

<h4>Examples</h4>

```
'hello'.startsWith('he')
```
{: .codeblock}

Returns true.
<br>

### matches

Tests whether the string operand matches regular expression.

<h4>Syntax</h4>

```
(string).matches(prefix (string))
```
{: .codeblock}

returns: a boolean value of whether the string matches the specified regular expression.

<h4>Examples</h4>

```
'Hello'.matches('[Hh]ello')
```
{: .codeblock}

Returns true.
<br>

### getDate

Get day of month from the date with timezone (default UTC), one-based indexing.

<h4>Syntax</h4>

```
(timestamp).getDate([time_zone (string)])
```
{: .codeblock}

returns: the day of month with one-based indexing.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getDate()
```
{: .codeblock}

Returns 24.
<br>

### getDayOfMonth

Get day of month from the date with timezone (default UTC), zero-based indexing.

<h4>Syntax</h4>

```
(timestamp).getDayOfMonth([time_zone (string)])
```
{: .codeblock}

returns: the day of month with zero-based indexing.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getDayOfMonth()
```
{: .codeblock}

Returns 23.
<br>

### getDayOfWeek

Get day of week from the date with timezone (default UTC), zero-based indexing, zero for Sunday.

<h4>Syntax</h4>

```
(timestamp).getDayOfWeek([time_zone (string)])
```
{: .codeblock}

returns: the day of week with zero-based indexing.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getDayOfWeek()
```
{: .codeblock}

Returns 5.
<br>

### getDayOfYear

Get day of year from the date with timezone (default UTC), zero-based indexing.

<h4>Syntax</h4>

```
(timestamp).getDayOfYear([time_zone (string)])
```
{: .codeblock}

returns: the day of year with zero-based indexing.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getDayOfYear()
```
{: .codeblock}

Returns 205.
<br>

### getFullYear

Get year from the date with timezone (default UTC).

<h4>Syntax</h4>

```
(timestamp).getFullYear([time_zone (string)])
```
{: .codeblock}

returns: the year from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getFullYear()
```
{: .codeblock}

Returns 2020.
<br>

### getMonth

Get month from the date with timezone, 0-11.

<h4>Syntax</h4>

```
(timestamp).getMonth([time_zone (string)])
```
{: .codeblock}

returns: the month from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getMonth()
```
{: .codeblock}

Returns 6.
<br>

### getHours

Get hours from the date with timezone, 0-23.

<h4>Syntax</h4>

```
(timestamp).getHours([time_zone (string)])
```
{: .codeblock}

returns: the hour from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getHours()
```
{: .codeblock}

Returns 9.
<br>

### getMinutes

Get minutes from the date with timezone, 0-59.

<h4>Syntax</h4>

```
(timestamp).getMinutes([time_zone (string)])
```
{: .codeblock}

returns: the minute from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getMinutes()
```
{: .codeblock}

Returns 7.
<br>

### getSeconds

Get seconds from the date with timezone, 0-59.

<h4>Syntax</h4>

```
(timestamp).getSeconds([time_zone (string)])
```
{: .codeblock}

returns: the second from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.000-00:00').getSeconds()
```
{: .codeblock}

Returns 29.
<br>

### getMilliseconds

Get milliseconds from the date with timezone, 0-999.

<h4>Syntax</h4>

```
(timestamp).getMilliseconds([time_zone (string)])
```
{: .codeblock}

returns: the millisecond from the date.

<h4>Examples</h4>

```
timestamp('2020-07-24T09:07:29.021-00:00').getMilliseconds()
```
{: .codeblock}

Returns 21.
<!--End of OF extended functions-->

**Parent topic:** [Adding conditions to a {{ site.data.keyword.pipeline }}](ml-orchestration-conditions.html)



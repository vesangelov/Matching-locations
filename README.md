# Matching-locations

3. Matching Locations
Write a program that reads names of places and their geographical coordinates in the format
name,latitude,longitude (where latitude and longitude are floating-point numbers). No two locations will
have the same name. Some locations may have the same coordinates.
After all locations are entered, a single line containing the '.' (dot) character will be entered.
After that, queries will be entered – the queries will either contain a name of a location, or latitude and
longitude coordinates (entered as two floating point numbers separated by a single space). Print all locations that
match the query in the same format that they were entered.
After all queries are entered, a single line containing the '.' (dot) character will be entered.

Examples

Input
Sofia,42.70,23.33
New York,40.6976701,-74.2598732
SoftUni,42.70,23.33
.
Sofia
40.6976701 -74.2598732
42.70 23.33
.

Output
Sofia,42.70,23.33
New York,40.6976701,-74.2598732
Sofia,42.70,23.33
SoftUni,42.70,23.33

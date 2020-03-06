#!/bin/bash

# input data:
in='
H4sIAPD8jFcAA2NiAIMjmQWJKSlFCi7BIfGeATpQXnCQM4hXmplXYmaiEOQaGO8UGeIaDBcIDoAK
lGTmpiqEePq6xrt5BgWHIPF9HIFckHpjIwXXMFc/oPEuMD7IQDcf//BgZIEAR2dv1xCEENAOVDVA
AWQ1hmZgZwb4B4UwMDCfZghjgALt52zV/4EAxj9cGPQNxO/zYATzl9hbg+lj3uacG+/phunfVTlm
/Ug3DCTLxwrBS5kZGN5xMTCYMiDMrdyh9xebufe5oeautQTT/r3T3+0Bmnvz3PdgR6C5TEAxeRYI
7gGauwTN3PXaxf+xuteHCcw3NK8G03lCzQe2Ac09cGrhUmegucwg93JC8BR2BobdYqjmrv0nI4hs
7uSnjMEg/lNdiLl9vwtg4fByH9BcoPFZLkBzgc5kuM0BwUpAc9NEUc213WQgjM29M6Ug4aA9ywFM
R1huydgPNPf3yo+TQOYCg5UhkgWCfwId/5ob1dyi61W3sJkbcw9ibix3Ipie+3652iGguVEp1vLu
QHPZgGIx7BD8A2jJc0H84XC4cMIhEL/KAhIOrsmlYNox4ekGkLm2XNcPg8wFGsfAxgnBwUDOT1FC
4SuwCsS30YCYez+9CEyvkYlSOQw0l2ONjJUX0FxgsDIc4YBgS6C5q9HMrdT42I8tHGZoQcLB/Rgk
/U6WYCkDhW/cLs8cb6C5QGcyzGCB4LXA8GVHC9+aFy1x2MzdGAvh9/0SBdNva+xNtwDNFVnnfhCU
L4DJlaGQEYKjgJiPBdXcRZ/rw7CZq68AcW9wkh0kPPx7zQ8CzXXuzmH3A5oLdB5DPgsEXwe6twni
XkYGAJhUtVSbBAAA
'

# output data:
out='
H4sIAAEMM14AA+WabWvcRhDH3/dThHvdFTs7s09+l9gJ5E0asKHQUsqutBeO2j5zPqe4od+9I92d
Ld1uozuQQ3oFG4ykXf01Mz/Ng/xldh7W6dNy9Tg7e/Xr7PXnsLgOcXG9WD9WFxfLy9lvP76afVg2
qT39ZXb5c3fZh3STwozPhJu768V8UYf1Ynn7e5PWqW7/2qwKN+2qWf1XVaf727Subttl1WDNZsly
Nfu7XfL2c7pdXy0265QELUAKZa6kO5Oaf35p73kVVp/SeqPn/e3HUP+R1ufLh9v2kLLe8SXvb988
rtPuIDqnPJju+Lvr5Z+74x6xPfaRumcirBRCZSpQ2On/uFqul92ph+auvXGzvAkLfrZO6rvl6ia0
u8zeX7x9Ldvz5yncp7J6Jc8AOvXnq8QG713lhVRC6iugM/JnanPV5fJhVafdM/ZFg/L0NXG9JwKv
KwCsnKoUme7UTw/rggUG1nIEIDeX/psRhzbfKrp6vOsEz97w2Xv27jqtdvfMndTZsLx/LrDo44su
csbM/aSq3bWz7Jrj7n7N4Xe9MdZFuzw0yaroUCSPWpCqkwgAc/YLAFlsZArNrLvpfb1a3HUxzssu
Ply+GoTz7O8fvvyHiAJzAFGKcqKsk1JSTpR0/fhTUIGjikyl9MswZadhSmo9HVMyfwMZp60uMNUz
4x5TG0XHMKUoZ+pp/1xg0ctjTNljmGqMYQHJCiQbBMXGi9BQFBhtE41WaCGeIlNylCntwOfvXWm1
1DZjCjzJfgBaXXGqAtAMlX4RqPwkUHEydZNBtTPCwGKgpbGFVNW35F6YbzQdjlXrqQyr5/0LEoue
HuPKH8OV9XXyDaGYcyIU5JUVXstaYG1Sit5GjyeZq9w4V2Tzd68lSYQy58opM+CK6z9NlXIV2JfA
SslpsFLGHooV2UopX0HlsAjV1gJDqEg5BTlUfTPuQbVRdARU7KYMquf9CxKLbh6BamvvQ6FKztfo
SFhdcwHYkBZRzxuBc0h1oMC1oTtFqPwoVMg1cBYlpBCthRwqCbYXgYYLQOsqYqb8d8wUcPKZLlVt
TTB8CSmkQgHYN+NeAbiRdDhUrZsyqJ73LygsunlSqEwTa2jQCBU9CHKOK0BDUtQ1cLul58lHfYJQ
KTUKFWmXd94GtfeyAJVWg7YKOEtx+QeKYxDci3CF03Dl3HSzip0VhtlK8dWFErBvyj2wNpoOB6t1
VQbW8/4FiUVXj4GFR2UrAxBUkzhH+SiIEohYYxRaRo1zhfU8wv8TLG2Uzt++xiNsjw/js+vKv10J
OA1W3MXII7ECIk7BVK4CbW4xIK2xwFXfkllrJY+rAtlTeRX4tH9BYtHTk3LlmmRC0HNhojeC5NyI
IM1ckE0gOYMn1naKXOE4V1x0F1orzw4rcUX+m3JlJmqt6OB0tWutDD+SLGNF+YwHCNCqUnP1bMj9
5oqOS1etowrN1W7/gsSio8ewMsdgheAADXdTzrFPCJUX3qXIbCFG4jqQrD9BrA5orrjXzutA9EzM
tj4cDG4J+iGooCLJ1RL3WPQi03U10XQdrJmsCtzaYC+9E5W+WPXMuN9cdYqOmK6zm/Lp+tP+ucCi
l8eYOmq6roOCOaS5CDo2gsAl4VGRMFraRkmD0aoTZEqOTwE5UxcaBQ4R3H4b7rsLaTAEVJylUFXA
v9tq6fv8CozGT4bU1gQDcym2VWFe0bfi3vigE3Q4Ua2TMqKet8/1FX086Tdgy+koSmtEE5GJchSF
k00QjTHWKeBisD5Forax9tUs5QshQpI7aVnIUq7/XxVg2rjjBkTZypmXIAqnmgHihN+AC9Mdi7b0
Dbhvxv0shUd+A2Y35SPAp/1zgUUvjzCFR00AQ4zQUIwCpWamYjDCe2mFb4J2qLjLag4dVPwDvxON
U6okAAA=
'

test -z "$srcdir" && export srcdir=.

. $srcdir/../test.sh

test_conversion "amplification" "amplification" "$in" "$out"


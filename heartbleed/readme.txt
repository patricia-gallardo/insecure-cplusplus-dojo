# Fixing Heartbleed

Here we will be fixing the code behind Heartbleed.

The vulnerability was in the function dtls1_process_heartbeat. The function has
been copied directly from OpenSSL only adding a few types to make it compile.

Task:

* Remove the ifdef that disables the last two tests.
* Make all the tests pass.

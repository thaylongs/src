#!/bin/sh
# simple test to ensure messages get sent on failed post-commits
echo "post-commit failed" 1>&2
echo "post-commit failed" 1>&2
echo "post-commit failed" 1>&2
echo "here!" 
exit 1

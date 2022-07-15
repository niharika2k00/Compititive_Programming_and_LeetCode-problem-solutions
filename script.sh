
# -------------------------------------
#  SCRIPT FOR AUTO PUSH CODE IN GITHUB
# -------------------------------------

git add .

echo -n 'Enter the commit message  -->  '
read  commitMessage

git commit -m "$commitMessage"

# echo 'Enter Branch Name  -->  '
# read branch
git push origin main


#  -n  remove new line


# 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   aaea
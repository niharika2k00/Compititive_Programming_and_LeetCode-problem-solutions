
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


# 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   
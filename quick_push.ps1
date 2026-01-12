# Quick Push to GitHub Script
# Run this after creating your repository on GitHub

Write-Host "`n=== CINTA GitHub Push Helper ===" -ForegroundColor Cyan
Write-Host "`nYour code is committed and ready to push!" -ForegroundColor Green
Write-Host "Commit: e3e3f44 - 122 files, 9,202 lines" -ForegroundColor Yellow

Write-Host "`n=== Step 1: Create Repository on GitHub ===" -ForegroundColor Cyan
Write-Host "A browser window should open to create a new repository." -ForegroundColor White
Write-Host "Repository name: Cinta-vst" -ForegroundColor Yellow
Write-Host "DO NOT initialize with README" -ForegroundColor Red

Write-Host "`n=== Step 2: Enter Your Repository URL ===" -ForegroundColor Cyan
$repoUrl = Read-Host "Paste your GitHub repository URL (e.g., https://github.com/username/Cinta-vst.git)"

if ([string]::IsNullOrWhiteSpace($repoUrl)) {
    Write-Host "`nNo URL provided. Exiting..." -ForegroundColor Red
    exit 1
}

Write-Host "`n=== Step 3: Adding Remote and Pushing ===" -ForegroundColor Cyan

# Add remote
Write-Host "Adding remote origin..." -ForegroundColor Yellow
git remote add origin $repoUrl

if ($LASTEXITCODE -ne 0) {
    Write-Host "Remote might already exist. Removing and re-adding..." -ForegroundColor Yellow
    git remote remove origin
    git remote add origin $repoUrl
}

# Push to GitHub
Write-Host "`nPushing to GitHub..." -ForegroundColor Yellow
Write-Host "You may be prompted to authenticate." -ForegroundColor Cyan
git push -u origin main

if ($LASTEXITCODE -eq 0) {
    Write-Host "`n✓ SUCCESS! Your CINTA project is now on GitHub!" -ForegroundColor Green
    Write-Host "`nRepository URL: $repoUrl" -ForegroundColor Cyan
    Write-Host "`nView your repository:" -ForegroundColor White
    $viewUrl = $repoUrl -replace '\.git$', ''
    Write-Host $viewUrl -ForegroundColor Yellow
    
    # Open repository in browser
    Start-Process $viewUrl
} else {
    Write-Host "`n✗ Push failed. Check the error messages above." -ForegroundColor Red
    Write-Host "`nCommon issues:" -ForegroundColor Yellow
    Write-Host "- Authentication failed: Make sure you're logged into GitHub" -ForegroundColor White
    Write-Host "- Repository not found: Check the URL is correct" -ForegroundColor White
    Write-Host "- Permission denied: Verify you own the repository" -ForegroundColor White
}

Write-Host "`n=== Done ===" -ForegroundColor Cyan

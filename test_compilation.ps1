# Test CINTA Compilation After Cmajor Update
# Run this script after updating Cmajor tools

$cmajPath = "C:\Users\class\.vscode\extensions\cmajorsoftware.cmajor-tools-1.0.3088-win32-x64\bin\cmaj.exe"
$patchPath = "C:\Users\class\Documents\Cinta-vst\CINTA.cmajorpatch"

Write-Host "`n=== Checking Cmajor Version ===" -ForegroundColor Cyan
& $cmajPath --version

Write-Host "`n=== Testing CINTA Compilation (Dry Run) ===" -ForegroundColor Cyan
Write-Host "This will build the patch without playing audio..." -ForegroundColor Yellow

& $cmajPath play $patchPath --dry-run

if ($LASTEXITCODE -eq 0) {
    Write-Host "`n✓ SUCCESS! CINTA compiled without errors!" -ForegroundColor Green
    Write-Host "`nYou can now run the patch with:" -ForegroundColor Cyan
    Write-Host "  cmaj play CINTA.cmajorpatch" -ForegroundColor White
} else {
    Write-Host "`n✗ Compilation failed with exit code: $LASTEXITCODE" -ForegroundColor Red
    Write-Host "`nCheck the error messages above." -ForegroundColor Yellow
    Write-Host "If the internal compiler error persists, we may need to simplify the architecture." -ForegroundColor Yellow
}

Write-Host "`n=== Next Steps ===" -ForegroundColor Cyan
Write-Host "1. If compilation succeeded, try: cmaj play CINTA.cmajorpatch" -ForegroundColor White
Write-Host "2. If it failed, check FINAL_STATUS.md for alternative approaches" -ForegroundColor White
Write-Host "3. The vintage UI can be tested standalone at ui/index-vintage.html" -ForegroundColor White

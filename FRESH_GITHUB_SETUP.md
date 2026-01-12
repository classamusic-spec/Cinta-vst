# Fresh GitHub Setup for CINTA

## ✅ Credentials Cleared

Your old GitHub credentials have been removed. You're ready for a fresh login!

## Step 1: Log Into GitHub

Open your browser and go to: **https://github.com**

Log in with the account you want to use for this project.

## Step 2: Create New Repository

1. Click the **"+"** icon (top right) → **"New repository"**
2. Fill in:
   - **Repository name:** `Cinta-vst`
   - **Description:** `CINTA Synthesizer - Vintage 1975 Havana Studio Synth with 100 Presets`
   - **Public** or **Private** (your choice)
   - **DO NOT** check "Initialize with README"
3. Click **"Create repository"**

## Step 3: Connect and Push

After creating the repository, GitHub will show you setup commands. 

**Run these commands in PowerShell:**

```powershell
# Navigate to project
cd C:\Users\class\Documents\Cinta-vst

# Stage all files
git add .

# Create initial commit
git commit -m "Initial commit: CINTA Synthesizer

- 100 professional presets (keys, bass, pads, leads, arps, latin)
- Vintage 1975 Havana studio UI
- 3 synthesis engines: FM, Tape, Analog
- Expanded arpeggiator with Latin patterns
- Complete DSP implementation in Cmajor"

# Add your GitHub repository (REPLACE with your actual URL from GitHub)
git remote add origin https://github.com/YOUR_USERNAME/Cinta-vst.git

# Push to GitHub
git branch -M main
git push -u origin main
```

## Step 4: Authenticate

When you run `git push`, Windows will prompt you to authenticate.

**You'll see a login window** - use one of these methods:

### Option A: Browser Authentication (Easiest)
1. Click "Sign in with your browser"
2. Browser opens → log into GitHub
3. Authorize Git Credential Manager
4. Done! Credentials saved for future use

### Option B: Personal Access Token
1. Go to GitHub → Settings → Developer settings → Personal access tokens
2. Generate new token (classic)
3. Select scope: `repo`
4. Copy the token
5. Paste when prompted for password

## Verify Upload

After pushing, visit your repository on GitHub:
```
https://github.com/YOUR_USERNAME/Cinta-vst
```

You should see:
- ✓ All source files in `src/`
- ✓ Vintage UI files in `ui/`
- ✓ 100 presets in `presets/`
- ✓ Documentation files

## Quick Commands Reference

```powershell
# Check what's changed
git status

# Add changes
git add .

# Commit changes
git commit -m "Your message"

# Push to GitHub
git push

# Pull latest
git pull
```

## Troubleshooting

**"Authentication failed"**
- Close any credential prompts and try again
- Make sure you're logged into the correct GitHub account in your browser

**"Repository not found"**
- Double-check the repository URL in the `git remote add` command
- Make sure the repository exists on GitHub

**"Permission denied"**
- Verify you're logged into the correct GitHub account
- Check that the repository belongs to your account

---

## Ready to Go!

1. ✅ Old credentials cleared
2. ⏳ Log into GitHub
3. ⏳ Create repository
4. ⏳ Run the commands above
5. ✅ CINTA saved to GitHub!

**Your project includes:**
- 6 Cmajor DSP files
- 3 vintage UI files (HTML, CSS, JS)
- 100 preset JSON files
- Complete documentation
- Git configuration ready

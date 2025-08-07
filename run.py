import os
import subprocess
import shutil

# ✅ 填写你自己的信息
GITHUB_REPO = "https://github.com/yourname/your-repo.git"
SENSITIVE_TEXT = "your@email.com"
README_CURRENT_PATH = "/absolute/path/to/latest/README.md"

# ✅ 派生目录名
REPO_NAME = GITHUB_REPO.split("/")[-1].replace(".git", "")
MIRROR_DIR = f"{REPO_NAME}.git"
CLEANED_DIR = f"{REPO_NAME}-cleaned"

def run(cmd, cwd=None):
    print(f"\n[Running]: {cmd}")
    subprocess.run(cmd, cwd=cwd, shell=True, check=True)

def main():
    # Step 1: clone --mirror
    if os.path.exists(MIRROR_DIR):
        shutil.rmtree(MIRROR_DIR)
    run(f"git clone --mirror {GITHUB_REPO}")

    # Step 2: filter-repo 删除敏感内容
    run(f"""git filter-repo --replace-text <(echo "{SENSITIVE_TEXT}==") --force""", cwd=MIRROR_DIR)

    # Step 3: 重新 clone 干净仓库
    if os.path.exists(CLEANED_DIR):
        shutil.rmtree(CLEANED_DIR)
    run(f"git clone {MIRROR_DIR} {CLEANED_DIR}")

    # Step 4: 恢复 README 当前版本（从本地文件复制）
    readme_dst = os.path.join(CLEANED_DIR, "README.md")
    shutil.copyfile(README_CURRENT_PATH, readme_dst)

    # Step 5: 合并入最后一个 commit，保持历史整洁
    run("git add README.md", cwd=CLEANED_DIR)
    run("git commit --amend --no-edit", cwd=CLEANED_DIR)

    # Step 6: 强推回 GitHub
    run(f"git remote add origin {GITHUB_REPO}", cwd=CLEANED_DIR)
    run("git push --force --all", cwd=CLEANED_DIR)
    run("git push --force --tags", cwd=CLEANED_DIR)

    print("\n✅ 敏感信息清除完成，README 内容保持当前一致，commit/diff 全部擦除。")

if __name__ == "__main__":
    main()

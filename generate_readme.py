import os
import json

PROJECTS_DIR = "Projects"
README_FILE = "README.md"
PLACEHOLDER = "<!-- PROJECT-LIST-AUTO -->"

# Gather all project JSON files
project_jsons = [f for f in os.listdir(PROJECTS_DIR) if f.endswith(".json")]

# Build markdown for projects
project_md = ""
for pj in project_jsons:
    with open(os.path.join(PROJECTS_DIR, pj), "r", encoding="utf-8") as f:
        data = json.load(f)
    title = data.get("name", "")
    desc = data.get("description", "")
    techs = ", ".join(data.get("techs", []))
    
    project_md += f"### {title}\n\n{desc}\n\n**Technologies:** {techs}\n\n"

# Read existing README
with open(README_FILE, "r", encoding="utf-8") as f:
    readme = f.read()

# Replace placeholder section
if PLACEHOLDER in readme:
    updated_readme = readme.split(PLACEHOLDER)[0] + PLACEHOLDER + "\n\n" + project_md
    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(updated_readme)
    print("README.md updated with project list!")
else:
    print(f"Placeholder {PLACEHOLDER} not found in README.md")

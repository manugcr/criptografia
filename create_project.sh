#!/bin/bash

# Check if both project number and title were provided
if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Provide both a project number and a project title as arguments."
  echo "Example: sh create_project.sh 4 'Sistemas embebidos'"
  exit 1
fi

# Assign variables for the project number and title
PROJECT_NUMBER="$1"
PROJECT_TITLE="$2"

# Create the directory with the project number
PROJECT_DIR="tp$PROJECT_NUMBER"
mkdir -p "$PROJECT_DIR/imgs"

# Create the README.md file with the specified content
README_PATH="$PROJECT_DIR/README.md"
cat <<EOL > "$README_PATH"
# Criptografia y Seguridad en Redes

## Trabajo Practico $PROJECT_NUMBER - $PROJECT_TITLE

### Integrantes:

- Cabrera, Augusto Gabriel
- Gil Cernich, Manuel
- Mayorga, Federica

---
EOL

echo "Project directory $PROJECT_DIR created."

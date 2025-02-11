# GitHub Actions

## GITHUB_TOKEN
- Getting this error from a GitHub Action step?
```
Error: Resource not accessible by integration
```
- The GITHUB_TOKEN needs to have read and write enabled
  - Repo > Settings > Actions > General

![Screenshot of Workflow permissions selecting Read and write permissions](../../assets/workflow_permissions.png)

